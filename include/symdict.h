#ifndef __SYMTABLE_H
#define __SYMTABLE_H

#include <parser.h>

#ifndef MAX_SYMDICT_SIZE
#define MAX_SYMDICT_SIZE 100
#endif

struct tokeninfo {
  char *txt;
  int lineno;
  int colno;
};

typedef struct {

} typeinfo;

typedef struct symval {
  char *name;
  int lineno;
  int clumon;
  typeinfo type;
  struct symval *next; // used to handle collision key
} symval_t;

typedef struct symdict {
  int count;
  symval_t *data[MAX_SYMDICT_SIZE];
} symdict_t;

struct tokeninfo *symdict_create_tokeninfo(int lineno, int colno, char *txt);
symdict_t *symdict_create();
symval_t *symdict_create_symval(int lineno, int colno, char *name);
void symdict_add(symdict_t *dict, const char *key, symval_t *val);
void symdict_del(symdict_t *dict, const char *key);
symval_t *symdict_get(symdict_t *dict, const char *key);
void symdict_dump(symdict_t *dict);

#endif