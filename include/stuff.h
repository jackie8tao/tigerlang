#ifndef __STUFF_H
#define __STUFF_H

#include <parser.h>

void errmsg(const char *format, ...);
const char *token_type_to_str(yytoken_kind_t token_type);

#ifndef simple_msg
#define simple_msg(s) errmsg("%s, %d: %s", __FILE__, __LINE__, s);
#endif

// dynamic array
typedef struct {
  int count;
  int cap;
  void *data;
} tiger_list;

typedef void (*tiger_list_dump_fn)(void *);

tiger_list *tiger_list_init();
void tiger_list_append(tiger_list *list, void *data);
void tiger_list_free(tiger_list *list);
void tiger_list_dump(tiger_list *list, tiger_list_dump_fn fn);

#endif