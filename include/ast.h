#ifndef __AST_H
#define __AST_H

#include <parser.h>
#include <scope.h>

typedef enum ast_type {
  AstIdent,
  AstStruct,
  AstBinory,
  AstAssign,
  AstUnary,
  AstStmt,
  AstExpr,
  AstLvalue,
  AstExprList,
  AstExprSeq,
  AstFieldList,
  AstDecList,
  AstTypeFields,
  AstTypeId,
  AstType,
  AstTypeDec,
  AstDec,
  AstVarDec,
  AstFncall,
  AstTypeField,
  AstString,
  AstInt,
  AstNil,
  AstIndex,
  AstArrDef,
  AstIf,
  AstWhile,
  AstFor,
  AstLet,
} ast_type_t;

struct ast_node;

typedef struct ast_string {
  const char *str;
} ast_string_t;

typedef struct ast_int {
  int ival;
} ast_int_t;

typedef struct ast_nil {
} ast_nil_t;

typedef struct ast_binory_expr {
  yytoken_kind_t op;
  struct ast_node *left;
  struct ast_node *right;
} ast_binory_expr_t;

typedef struct ast_unary_expr {
  yytoken_kind_t op;
  struct ast_node *val;
} ast_unary_expr_t;

typedef struct ast_lvalue {
  const char *name;
} ast_lvalue_t;

typedef struct ast_assign_expr {
  struct ast_node *var;
  struct ast_node *expr;
} ast_assign_expr_t;

typedef struct ast_fncall {
  struct ast_node *fnname;
  struct ast_node *params;
} ast_fncall_t;

typedef struct ast_struct {
  struct ast_node *name;
  struct ast_node *fields;
} ast_struct_t;

typedef struct ast_arraydef {
  struct ast_node *type;
  struct ast_node *size;
  struct ast_node *initval;
} ast_arraydef_t;

typedef struct ast_if {
  struct ast_node *cond;
  struct ast_node *thexpr;
  struct ast_node *elexpr;
} ast_if_t;

typedef struct ast_while {
  struct ast_node *cond;
  struct ast_node *do_expr;
} ast_while_t;

typedef struct ast_for {
  struct ast_node *itor;
  struct ast_node *start;
  struct ast_node *end;
  struct ast_node *expr;
} ast_for_t;

typedef struct ast_let {
  struct ast_node *declist;
  struct ast_node *exprseq;
} ast_let_t;

typedef struct ast_exprseq {
  int count;
  int cap;
  struct ast_node **exprseq;
} ast_exprseq_t;

typedef struct ast_exprlist {
  int count;
  struct ast_node **exprlist;
} ast_exprlist_t;

typedef struct ast_ident {
  const char *name;
  scope_t *sc;
} ast_ident_t;

typedef struct ast_node {
  ast_type_t type;
  union {
    ast_string_t *str;
    ast_int_t *ival;
    ast_nil_t *empty;
    ast_binory_expr_t *binexpr;
    ast_unary_expr_t *unexpr;
    ast_lvalue_t *lvalue;
    ast_assign_expr_t *assexpr;
    ast_fncall_t *fncall;
    ast_struct_t *st;
    ast_arraydef_t *arraydef;
    ast_if_t *ifexpr;
    ast_while_t *whexpr;
    ast_for_t *forexpr;
    ast_let_t *letexpr;
    ast_ident_t *ident;
    ast_exprlist_t *exprlist;
    ast_exprseq_t *exprseq;
  };
} ast_node_t;

ast_node_t *ast_create_if_node(ast_node_t *cond, ast_node_t *then_expr,
                               ast_node_t *else_expr);
ast_node_t *ast_create_arraydef_node(ast_node_t *type, ast_node_t *size,
                                     ast_node_t *initval);
ast_node_t *ast_create_exprseq();
ast_node_t *ast_create_ident_node(const char *name, scope_t *sc);
ast_node_t *ast_create_struct_node(ast_node_t *name, ast_node_t *fields);
ast_node_t *ast_create_fncall_node(ast_node_t *fnname, ast_node_t *params);
ast_node_t *ast_create_nil_node();
ast_node_t *ast_create_int_node(int ival);
ast_node_t *ast_create_string_node(const char *str);
ast_node_t *ast_create_binory_node(yytoken_kind_t op, ast_node_t *left,
                                   ast_node_t *right);
ast_node_t *ast_create_assign_node(ast_node_t *var, ast_node_t *expr);
ast_node_t *ast_create_unary_node(yytoken_kind_t op, ast_node_t *val);
ast_node_t *ast_create_while_node(ast_node_t *cond, ast_node_t *do_expr);
ast_node_t *ast_create_for_node(ast_node_t *it, ast_node_t *start,
                                ast_node_t *end, ast_node_t *expr);
ast_node_t *ast_create_let_node(ast_node_t *declist, ast_node_t *exprseq);

#endif