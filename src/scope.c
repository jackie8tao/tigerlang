#include <scope.h>
#include <stdio.h>
#include <stdlib.h>
#include <stuff.h>
#include <tigerdef.h>

static int _gsc_id = 1;
static scope_t *_cur_scope = NULL;

scope_t *scope_current() {
  if (!_cur_scope) {
    simple_msg("invalid scope");
    exit(ERR_SCOPE);
  }
  return _cur_scope;
}

scope_t *scope_create() {
  scope_t *sc = (scope_t *)malloc(sizeof(scope_t));
  if (!sc)
    goto memerr;
  sc->id = _gsc_id;
  sc->children = (scope_t **)malloc(SCOPE_INIT_CAP * sizeof(scope_t *));
  if (!sc->children)
    goto memerr;
  sc->children_cap = SCOPE_INIT_CAP;
  sc->children_count = 0;
  sc->parent = NULL;
  sc->symdict = symdict_create();
  goto succ;
memerr:
  simple_msg("invalid memory");
  exit(ERR_MEM);
succ:
  _gsc_id++;

  if (!_cur_scope) {
    _cur_scope = sc;
    return sc;
  }

  // chang current scope and set new scope parent
  sc->parent = _cur_scope;
  scope_append(_cur_scope, sc);
  _cur_scope = sc;
  return sc;
}

void scope_close() {
  if (!_cur_scope || !_cur_scope->parent)
    return;
  _cur_scope = _cur_scope->parent;
}

void scope_add_sym(scope_t *sc, symval_t *val) {
  symdict_add(sc->symdict, val->txt, val);
}

symval_t *scope_get_sym(scope_t *sc, const char *key) {
  return symdict_get(sc->symdict, key);
}

static void scope_resize_children(scope_t *sc) {
  if (sc->children_count < sc->children_cap)
    return;
  sc->children_cap = 2 * sc->children_cap;
  scope_t **new_children =
      (scope_t **)malloc(sc->children_cap * sizeof(scope_t *));
  if (!new_children) {
    simple_msg("invalid memory");
    exit(ERR_MEM);
  }
  for (int i = 0; i < sc->children_count; i++)
    new_children[i] = sc->children[i];
  free(sc->children);
  sc->children = new_children;
}

void scope_append(scope_t *dest, scope_t *src) {
  if (!dest || !src)
    exit(ERR_ARGS);
  if (dest->children_count >= dest->children_cap)
    scope_resize_children(dest);
  src->parent = dest;
  dest->children[dest->children_count] = src;
  dest->children_count++;
}

scope_t *scope_get(scope_t *sc, int scope_id) {
  if (sc->id == scope_id)
    return sc;
  if (sc->children_count <= 0)
    return NULL;
  for (int i = 0; i < sc->children_count; i++) {
    scope_t *tmp = scope_get(sc->children[i], scope_id);
    if (tmp) {
      return tmp;
    }
  }
  return NULL;
}

void scope_dump(scope_t *sc) {
  printf("scope: %d, count: %d\n", sc->id, sc->children_count);
  symdict_dump(sc->symdict);
  for (int i = 0; i < sc->children_count; i++) {
    scope_t *tmp = sc->children[i];
    printf("scope: %d, count: %d\n", tmp->id, tmp->children_count);
    symdict_dump(tmp->symdict);
  }
}