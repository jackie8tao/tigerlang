#ifndef __STXTREE_H
#define __STXTREE_H

#include <parser.h>
#include <tigerdef.h>

typedef union token_val
{
    char *sym;  // symbol value
    int ival;   // integer value
    char *sval; // string value
} token_val_t;

typedef struct stxnode
{
    yytoken_kind_t token_type;
    token_val_t *token_val;
    int count; // children node count
    int cap;   // capacity of node children list
    struct stxnode **children;
    int deep; // tree deep is used to travel tree
} stxnode_t;

typedef struct stxtree
{
    stxnode_t *root;
} stxtree_t;

void stxtree_init();
stxtree_t* stxtree_get();
void stxtree_reset();
stxnode_t *stxtree_create_node(yytoken_kind_t token_type);
void stxtree_append_node(stxnode_t *dest, stxnode_t *src);
stxnode_t *stxtree_create_string_node(const char *str);
stxnode_t *stxtree_create_integer_node(int val);
stxnode_t *stxtree_create_ident_node(const char *ident);
void stxtree_show_all();
void stxtree_show_node(yytoken_kind_t token_type);

#endif