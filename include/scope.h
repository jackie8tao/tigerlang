#ifndef __SCOPE_H
#define __SCOPE_H

#include <symdict.h>

typedef struct scope {
  int id;
  symdict_t *symdict;
  struct scope *parent;
  struct scope **children;
  int children_cap;
  int children_count;
} scope_t;

scope_t *scope_create();
void scope_add_sym(scope_t *sc, symval_t *val);
symval_t *scope_get_sym(scope_t *sc, const char *key);
void scope_append(scope_t *dest, scope_t *src);
scope_t *scope_get(scope_t *sc, int scope_id);
void scope_dump(scope_t *sc);

#endif