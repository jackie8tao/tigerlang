#ifndef __AST_H
#define __AST_H

#include <parser.h>
#include <scope.h>
#include <stdlib.h>

typedef enum {
  AstString,
  AstIdent,
  AstStruct,
  AstBinory,
  AstAssign,
  AstUnary,
  AstInt,
  AstNil,
  AstArrInit,
  AstIf,
  AstWhile,
  AstFor,
  AstLet,
  AstExprList,
  AstExprSeq,
  AstFncall,
  AstFieldef,
  AstFieldList,
  AstIdentIndex,
  AstArrIndex,
  AstLvalue,
  AstIdentTypeDec,
  AstStTypeDec,
  AstArrTypeDec,
  AstIdentTypeId,
  AstStrTypeId,
  AstIntTypeId,
  AstTypeFields,
  AstVarDec,
  AstDecList,
  AstFnDef,
  AstBreak,
} ast_type;

struct ast_node;

typedef struct ast_node {
  ast_type type;
  union {
    struct {
      char *name;
      scope_t *sc;
    } ident;
    struct {
      struct ast_node *ident;
      struct ast_node *expr;
    } fieldef;
    struct {
      int count;
      int cap;
      struct ast_node **children;
    } fieldlist, exprseq, exprlist, declist;
    struct {
      yytoken_kind_t op;
      struct ast_node *left;
      struct ast_node *right;
    } binexpr, unexpr;
    struct {
      struct ast_node *var;
      struct ast_node *expr;
    } assexpr;
    struct {
      struct ast_node *ident;
      struct ast_node *index;
    } lvalue;
    struct {
      union {
        struct ast_node *arr_index;
        struct ast_node *ident_index;
      };
      struct ast_node *next;
    } idxexpr;
    struct {
      yytoken_kind_t type;
      union {
        char *sval;
        int ival;
      };
    } rvalue;
    struct {
      struct ast_node *name;
      struct ast_node *fields;
    } strt;
    struct {
      struct ast_node *type;
      struct ast_node *size;
      struct ast_node *initval;
    } arrinit;
    struct {
      struct ast_node *typeid;
      struct ast_node *typeval;
    } typedec;
    struct {
      struct ast_node *ident;
      struct ast_node *typeid;
      struct ast_node *next;
    } typefields;
    struct {
      struct ast_node *ident;
    } typeid;
    struct {
      struct ast_node *ident;
      struct ast_node *typeid;
      struct ast_node *expr;
    } vardec;
    struct {
      struct ast_node *fnname;
      struct ast_node *params;
      struct ast_node *rettype;
      struct ast_node *fnbody;
    } fndef;
    struct {
      struct ast_node *cond;
      struct ast_node *thexpr;
      struct ast_node *elexpr;
    } ifexpr;
    struct {
      struct ast_node *cond;
      struct ast_node *do_expr;
    } whexpr;
    struct {
      struct ast_node *itor;
      struct ast_node *start;
      struct ast_node *end;
      struct ast_node *expr;
    } forexpr;
    struct {
      struct ast_node *fnname;
      struct ast_node *params;
    } fncall;
    struct {
      struct ast_node *declist;
      struct ast_node *exprseq;
    } letexpr;
  };
} ast_node_t;

ast_node_t *ast_create_if(ast_node_t *cond, ast_node_t *then_expr,
                          ast_node_t *else_expr);
ast_node_t *ast_create_arrinit(ast_node_t *type, ast_node_t *size,
                               ast_node_t *initval);
ast_node_t *ast_create_exprseq();
void ast_append_exprseq(ast_node_t *cur, ast_node_t *src);
ast_node_t *ast_create_ident(char *name, scope_t *sc, int lineno, int colno);
ast_node_t *ast_create_struct(ast_node_t *name, ast_node_t *fields);
ast_node_t *ast_create_fncall(ast_node_t *fnname, ast_node_t *params);
ast_node_t *ast_create_nil();
ast_node_t *ast_create_int(int ival);
ast_node_t *ast_create_string(char *str);
ast_node_t *ast_create_binory(yytoken_kind_t op, ast_node_t *left,
                              ast_node_t *right);
ast_node_t *ast_create_assign(ast_node_t *var, ast_node_t *expr);
ast_node_t *ast_create_unary(yytoken_kind_t op, ast_node_t *val);
ast_node_t *ast_create_while(ast_node_t *cond, ast_node_t *do_expr);
ast_node_t *ast_create_for(ast_node_t *it, ast_node_t *start, ast_node_t *end,
                           ast_node_t *expr);
ast_node_t *ast_create_let(ast_node_t *declist, ast_node_t *exprseq);
ast_node_t *ast_create_exprlist();
void ast_append_exprlist(ast_node_t *cur, ast_node_t *src);
ast_node_t *ast_create_fieldef(ast_node_t *ident, ast_node_t *field);
ast_node_t *ast_create_fieldlist();
void ast_append_fieldlist(ast_node_t *cur, ast_node_t *src);
ast_node_t *ast_create_ident_index(ast_node_t *ident);
ast_node_t *ast_create_arr_index(ast_node_t *ival);
void ast_append_index(ast_node_t *cur, ast_node_t *next);
ast_node_t *ast_create_lvalue(ast_node_t *ident, ast_node_t *index);
ast_node_t *ast_create_ident_typeid(ast_node_t *ident);
ast_node_t *ast_create_int_typeid();
ast_node_t *ast_create_str_typeid();
ast_node_t *ast_create_typefields(ast_node_t *ident, ast_node_t *typeid);
void ast_append_typefields(ast_node_t *cur, ast_node_t *src);
ast_node_t *ast_create_vardec(ast_node_t *ident, ast_node_t *typeid,
                              ast_node_t *expr);
ast_node_t *ast_create_typedec(ast_type type, ast_node_t *ident,
                               ast_node_t *typeval);
ast_node_t *ast_create_declist();
void ast_append_declist(ast_node_t *cur, ast_node_t *src);
ast_node_t *ast_create_fndef(ast_node_t *fnname, ast_node_t *params,
                             ast_node_t *rettype, ast_node_t *fnbody);
ast_node_t *ast_create_break();

ast_node_t *ast_get_root();
void ast_set_root(ast_node_t *root);

void ast_show_node(ast_node_t *node);
#endif