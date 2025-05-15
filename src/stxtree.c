#include <tigerdef.h>
#include <stxtree.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <parser.h>
#include <stuff.h>

#ifndef ERRSTR_INVALID_MEM
#define ERRSTR_INVALID_MEM "invalid memory"
#endif

#ifndef ERRSTR_INVALID_PARAMS
#define ERRSTR_INVALID_PARAMS "invalid parameters"
#endif

static stxtree_t *_stree = NULL;

void stxtree_init()
{
  if (_stree)
    return;
  _stree = (stxtree_t *)malloc(sizeof(stxtree_t));
  _stree->root = NULL;
  return;
}

stxtree_t *stxtree_get()
{
  if (!_stree)
  {
    errmsg("invalid syntax tree");
    exit(ERR_SYSTEM);
  }
  return _stree;
}

// create keyword node without children and token val
stxnode_t *stxtree_create_node(yytoken_kind_t token_type)
{
  stxnode_t *node = (stxnode_t *)malloc(sizeof(stxnode_t));
  if (!node)
  {
    errmsg(ERRSTR_INVALID_MEM);
    exit(ERR_SYSTEM);
  }
  node->children = NULL;
  node->count = 0;
  node->cap = 0;
  node->token_type = token_type;
  node->token_val = NULL;
  return node;
}

static stxnode_t *stxtree_create_node_with_tokenval(yytoken_kind_t token_type, token_val_t *tkval)
{
  stxnode_t *node = (stxnode_t *)malloc(sizeof(stxnode_t));
  if (!node)
    goto memerr;

  node->token_type = token_type;
  node->count = 0;
  node->cap = 0;
  node->children = NULL;
  node->token_val = tkval;
  goto succ;

memerr:
  errmsg(ERRSTR_INVALID_MEM);
  exit(ERR_SYSTEM);
succ:
  return node;
}

static void stxtree_resize_node_children_list(stxnode_t *node)
{
  if (node->cap > node->count)
    return;
  int new_cap = 2 * node->count;
  stxnode_t **new_children = (stxnode_t **)malloc(new_cap * sizeof(stxnode_t *));
  if (!new_children)
  {
    errmsg(ERRSTR_INVALID_MEM);
    exit(ERR_SYSTEM);
  }
  for (int i = 0; i < node->count; i++)
    new_children[i] = node->children[i];
  free(node->children);
  node->children = new_children;
  node->cap = new_cap;
  return;
}

static int stxtree_node_children_len(stxnode_t *n)
{
  if (!n)
  {
    errmsg(ERRSTR_INVALID_PARAMS);
    exit(ERR_ARGS);
  }
  return n->count;
}

void stxtree_append_node(stxnode_t *dest, stxnode_t *src)
{
  if (!src)
    return;

  if (!dest->children)
  {
    stxnode_t **children = (stxnode_t **)malloc(STXTREE_INIT_CAP * sizeof(stxnode_t *));
    dest->children = children;
    dest->cap = STXTREE_INIT_CAP;
    dest->count = 0;
  }
  if (dest->count >= dest->cap)
    stxtree_resize_node_children_list(dest);

  dest->children[dest->count] = src;
  dest->count++;
  return;
}

// create string node
stxnode_t *stxtree_create_string_node(const char *str)
{
  token_val_t *tkval = (token_val_t *)malloc(sizeof(token_val_t));
  if (!tkval)
  {
    errmsg(ERRSTR_INVALID_MEM);
    exit(ERR_SYSTEM);
  }
  tkval->sval = strdup(str);

  return stxtree_create_node_with_tokenval(TK_STRING, tkval);
}

// create integer node
stxnode_t *stxtree_create_integer_node(int val)
{
  token_val_t *tkval = (token_val_t *)malloc(sizeof(token_val_t));
  if (!tkval)
  {
    errmsg(ERRSTR_INVALID_MEM);
    exit(ERR_SYSTEM);
  }
  tkval->ival = val;

  return stxtree_create_node_with_tokenval(TK_INTEGER, tkval);
}

stxnode_t *stxtree_create_ident_node(const char *ident)
{
  token_val_t *tkval = (token_val_t *)malloc(sizeof(token_val_t));
  if (!tkval)
  {
    errmsg(ERRSTR_INVALID_MEM);
    exit(ERR_SYSTEM);
  }
  tkval->sym = strdup(ident);

  return stxtree_create_node_with_tokenval(TK_IDENT, tkval);
}

static void stxtree_node_free(stxnode_t *node)
{
  if (!node)
    return;

  if (node->cap < 0)
  {
    free(node->token_val);
    free(node);
    return;
  }

  for (int i = 0; i < node->cap; i++)
  {
    stxtree_node_free(node->children[i]);
  }

  return;
}

// reset global syntax tree and free all node
void stxtree_reset()
{
  stxtree_node_free(_stree->root);
  free(_stree);
  _stree = NULL;
  return;
}

typedef struct node_queue
{
  int cap;
  int count;
  stxnode_t **data;
} node_queue_t;

static node_queue_t *node_queue_create()
{
  node_queue_t *q = (node_queue_t *)malloc(sizeof(node_queue_t));
  if (!q)
    goto errmem;

  q->cap = 10;
  q->count = 0;

  q->data = (stxnode_t **)malloc(q->cap * sizeof(stxnode_t *));
  if (!q->data)
    goto errmem;
  memset(q->data, 0, q->cap * sizeof(stxnode_t *));
  goto succ;

errmem:
  errmsg(ERRSTR_INVALID_MEM);
  exit(ERR_SYSTEM);
succ:
  return q;
}

static void node_queue_free(node_queue_t *q)
{
  if (!q)
    return;
  free(q->data);
  free(q);
}

static void node_queue_resize(node_queue_t *q)
{
  if (!q)
  {
    errmsg(ERRSTR_INVALID_PARAMS);
    exit(ERR_ARGS);
  }

  q->cap = 2 * q->cap;

  stxnode_t **new_data = (stxnode_t **)malloc(q->cap * sizeof(stxnode_t *));
  if (!new_data)
  {
    errmsg(ERRSTR_INVALID_MEM);
    exit(ERR_SYSTEM);
  }
  memset(new_data, 0, q->cap * sizeof(stxnode_t *));

  for (int i = 0; i < q->count; i++)
    new_data[i] = q->data[i];
  free(q->data);
  q->data = new_data;
  return;
}

static stxnode_t *node_queue_pop(node_queue_t *q)
{
  if (!q)
  {
    errmsg(ERRSTR_INVALID_PARAMS);
    exit(ERR_ARGS);
  }
  if (q->count <= 0)
    return NULL;

  stxnode_t *node = q->data[0];
  for (int i = 1; i < q->count; i++)
    q->data[i - 1] = q->data[i];
  q->data[q->count - 1] = NULL;
  q->count--;
  return node;
}

static void node_queue_push(node_queue_t *q, stxnode_t *node)
{
  if (!q || !node)
  {
    errmsg(ERRSTR_INVALID_PARAMS);
    exit(ERR_ARGS);
  }
  if (q->count >= q->cap)
    node_queue_resize(q);
  q->data[q->count] = node;
  q->count++;
  return;
}

static int node_queue_len(node_queue_t *q)
{
  if (!q)
  {
    errmsg(ERRSTR_INVALID_PARAMS);
    exit(ERR_ARGS);
  }
  return q->count;
}

static void stxtree_print_token(stxnode_t *n)
{
  switch (n->token_type)
  {
  case TK_INTEGER:
    printf("%d ", n->token_val->ival);
    break;
  case TK_STRING:
    printf("%s ", n->token_val->sval);
    break;
  case TK_IDENT:
    printf("%s ", n->token_val->sym);
    break;
  default:
    printf("%s ", token_type_to_str(n->token_type));
    break;
  }
}

static void stxtree_print_node(stxnode_t *n)
{

  stxtree_print_token(n);
  printf("\n");
  for (int i = 0; i < n->count; i++)
    stxtree_print_token(n->children[i]);
}

void stxtree_show_all()
{
  if (!_stree || !_stree->root)
    return;

  node_queue_t *q = node_queue_create();
  node_queue_push(q, _stree->root);

  stxnode_t *n = NULL;
  int prev_deep = 0;
  while (node_queue_len(q) > 0)
  {
    n = node_queue_pop(q);
    if (n->token_type == YYEMPTY)
      continue;

    // when prev deep is not equal n deep, we print '\n'
    if (prev_deep != n->deep)
      for (int i = 0; i < n->deep - prev_deep; i++)
        printf("\n");
    prev_deep = n->deep;

    stxtree_print_token(n);

    for (int i = 0; i < n->count; i++)
    {
      n->children[i]->deep = n->deep + 1;
      node_queue_push(q, n->children[i]);
    }
  }

  node_queue_free(q);

  return;
}

void stxtree_show_node(yytoken_kind_t token_type)
{
  if (!_stree || !_stree->root)
    return;

  node_queue_t *q = node_queue_create();
  node_queue_push(q, _stree->root);

  stxnode_t *n = NULL;
  while (node_queue_len(q) > 0)
  {
    n = node_queue_pop(q);
    if (n->token_type == token_type)
    {
      stxtree_print_node(n);
      break;
    }
    for (int i = 0; i < n->count; i++)
    {
      n->children[i]->deep = n->deep + 1;
      node_queue_push(q, n->children[i]);
    }
  }

  node_queue_free(q);

  return;
}