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
} stxnode_t;

typedef struct stxtree
{
    stxnode_t *root;
} stxtree_t;

void stxtree_init();
void stxtree_append_node(stxnode_t *dest, stxnode_t *src);
void stxtree_show();
stxnode_t *stxtree_create_binoper_node(yytoken_kind_t token_type);
stxnode_t *stxtree_create_string_node(const char *str);
stxnode_t *stxtree_create_integer_node(int val);
stxnode_t *stxtree_create_nil_node();
stxnode_t *stxtree_create_unary_minus_node();
stxnode_t *stxtree_create_ident_node(const char *ident);
stxnode_t *stxtree_create_assign_node();
stxnode_t *stxtree_create_break_node();

#endif