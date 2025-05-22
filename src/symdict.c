#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stuff.h>
#include <symdict.h>
#include <tigerdef.h>

symdict_t *symdict_create() {
  symdict_t *dict = (symdict_t *)malloc(sizeof(symdict_t));
  if (!dict) {
    errmsg("%s: invalid memory", __FILE__);
    exit(ERR_MEM);
  }
  memset(dict, 0, sizeof(symdict_t));
  return dict;
}

static int symdict_hash(const char *key) {
  int num = 0;
  for (int i = 0; i < strlen(key); i++)
    num += (int)key[i];
  return num % MAX_SYMDICT_SIZE;
}

void symdict_add(symdict_t *dict, const char *key, symval_t *val) {
  int i = symdict_hash(key);
  symval_t *cur = dict->data[i];
  if (!cur) {
    dict->data[i] = val;
    return;
  }

  symval_t *prev = NULL;
  while (cur) {
    int curlen = strlen(cur->txt);
    if (curlen != strlen(key)) {
      prev = cur;
      cur = cur->next;
      continue;
    }
    if (strncmp(cur->txt, key, curlen) != 0) {
      prev = cur;
      cur = cur->next;
      continue;
    }

    // find same key, so we update value
    cur->lineno = val->lineno;
    cur->type = val->type;
    cur->txt = val->txt;
    return;
  }

  prev->next = val;
  return;
}

void symdict_del(symdict_t *dict, const char *key) {
  int i = symdict_hash(key);
  symval_t *cur = dict->data[i];
  if (!cur)
    return;

  symval_t *prev = NULL;
  while (cur) {
    int curlen = strlen(cur->txt);
    if (curlen != strlen(key)) {
      prev = cur;
      cur = cur->next;
      continue;
    }
    if (strncmp(cur->txt, key, curlen) != 0) {
      prev = cur;
      cur = cur->next;
      continue;
    }
    // found the symval
    break;
  }
  prev->next = cur->next;
  free(cur);
  return;
}

symval_t *symdict_get(symdict_t *dict, const char *key) {
  int i = symdict_hash(key);
  symval_t *cur = dict->data[i];
  if (!cur)
    return NULL;

  while (cur) {
    int curlen = strlen(cur->txt);
    if (curlen != strlen(key)) {
      cur = cur->next;
      continue;
    }
    if (strncmp(cur->txt, key, curlen) != 0) {
      cur = cur->next;
      continue;
    }
    // found the symval
    break;
  }
  return cur;
}

void symdict_dump(symdict_t *dict) {
  symval_t *cur;
  for (int i = 0; i < MAX_SYMDICT_SIZE; i++) {
    cur = dict->data[i];
    while (!cur) {
      printf("line: %d, type: %d, txt: %s\n", cur->lineno, cur->type, cur->txt);
      cur = cur->next;
    }
  }
}

symval_t *symdict_create_symval(int lineno, yytoken_kind_t token_type,
                                char *txt) {
  symval_t *sym = (symval_t *)malloc(sizeof(symval_t));
  if (!sym) {
    simple_msg("invalid memory");
    exit(ERR_MEM);
  }
  sym->txt = txt;
  sym->type = token_type;
  sym->lineno = lineno;
  return sym;
}