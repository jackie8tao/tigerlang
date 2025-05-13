#include <tigerdef.h>
#include <stxtree.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <parser.h>
#include <stuff.h>

#define ERRSTR_INVALID_MEM "invalid memory"

static stxtree_t *_stree = NULL;

void stxtree_init()
{
    if (!_stree)
        return;
    stxtree_t *_stree = (stxtree_t *)malloc(sizeof(stxtree_t));
    _stree->root = NULL;
    return;
}

// create keyword node without any children
static stxnode_t *stxtree_create_keyword_node(yytoken_kind_t tokentype)
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
    node->token_type = tokentype;
    node->token_val = NULL;
    return node;
}

// static stxnode_t* stxtree_create_node_with_token

// create binoper node along with two children node
stxnode_t *stxtree_create_binoper_node(yytoken_kind_t token_type)
{
    stxnode_t *node = (stxnode_t *)malloc(sizeof(stxnode_t));
    if (!node)
        goto memerr;

    node->cap = 2;
    stxnode_t **children = (stxnode_t **)malloc(node->cap * sizeof(stxnode_t *));
    if (!children)
        goto memerr;

    node->token_type = token_type;
    node->count = 0;
    node->children = children;
    node->token_val = NULL;
    goto succ;

memerr:
    errmsg(ERRSTR_INVALID_MEM);
    exit(ERR_SYSTEM);
succ:
    return node;
}

stxnode_t *stxtree_create_break_node()
{
    return stxtree_create_keyword_node(TK_BREAK);
}

// create string node
stxnode_t *stxtree_create_string_node(const char *str)
{
    stxnode_t *node = (stxnode_t *)malloc(sizeof(stxnode_t));
    if (!node)
        goto memerr;

    token_val_t *tkval = (token_val_t *)malloc(sizeof(token_val_t));
    if (!tkval)
        goto memerr;
    tkval->sval = strdup(str);

    node->children = NULL;
    node->count = 0;
    node->cap = 0;
    node->token_type = TK_STRING;
    node->token_val = tkval;
    goto succ;

memerr:
    errmsg(ERRSTR_INVALID_MEM);
    exit(ERR_SYSTEM);
succ:
    return node;
}

// create integer node
stxnode_t *stxtree_create_integer_node(int val)
{
    stxnode_t *node = (stxnode_t *)malloc(sizeof(stxnode_t));
    if (!node)
        goto memerr;

    token_val_t *tkval = (token_val_t *)malloc(sizeof(token_val_t));
    if (!tkval)
        goto memerr;
    tkval->ival = val;

    node->children = NULL;
    node->cap = 0;
    node->count = 0;
    node->token_type = TK_INTEGER;
    node->token_val = tkval;
    goto succ;

memerr:
    errmsg(ERRSTR_INVALID_MEM);
    exit(ERR_SYSTEM);
succ:
    return node;
}

// create nil node
stxnode_t *stxtree_create_nil_node()
{
    return stxtree_create_keyword_node(TK_NIL);
}

// create unary minus operator node with one children.
stxnode_t *stxtree_create_unary_minus_node()
{
    stxnode_t *node = (stxnode_t *)malloc(sizeof(stxnode_t));
    if (!node)
        goto errmem;

    stxnode_t **children = (stxnode_t **)malloc(sizeof(stxnode_t *));
    if (!children)
        goto errmem;

    node->token_type = TK_MINUS;
    node->count = 0;
    node->cap = 1;
    node->children = children;
    node->token_val = NULL;
    goto succ;
errmem:
    errmsg(ERRSTR_INVALID_MEM);
    exit(ERR_SYSTEM);
succ:
    return node;
}

stxnode_t *stxtree_create_ident_node(const char *ident)
{
    stxnode_t *node = (stxnode_t *)malloc(sizeof(stxnode_t));
    if (!node)
        goto memerr;

    token_val_t *tkval = (token_val_t *)malloc(sizeof(token_val_t));
    if (!tkval)
        goto memerr;

    tkval->sym = strdup(ident);
    node->children = NULL;
    node->count = 0;
    node->token_type = TK_IDENT;
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

stxnode_t *stxtree_create_assign_node()
{
    stxnode_t *node = (stxnode_t *)malloc(sizeof(stxnode_t));
    if (!node)
        goto memerr;

    node->cap = 2;
    stxnode_t **children = (stxnode_t **)malloc(node->cap * sizeof(stxnode_t *));
    if (!children)
        goto memerr;

    node->token_type = TK_ASSIGN;
    node->count = 0;
    node->children = children;
    node->token_val = NULL;
    goto succ;

memerr:
    errmsg(ERRSTR_INVALID_MEM);
    exit(ERR_SYSTEM);
succ:
    return node;
}

void stxtree_show()
{
}