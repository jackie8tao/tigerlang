#ifndef __AST_H
#define __AST_H

#include <parser.h>
#include <scope.h>

typedef enum {
  AstString,
  AstIdent,
  AstStruct,
  AstBinory,
  AstAssign,
  AstUnary,
  AstInt,
  AstNil,
  AstArrDef,
  AstIf,
  AstWhile,
  AstFor,
  AstLet,
  AstExprList,
  AstExprSeq,
  AstFncall,
  AstFieldef,
  AstFieldList,
  AstIndex,
  AstIdentIndex,
  AstArrIndex,
  AstLvalue,
  AstTypeDec,
  AstTypeId,
  AstTypeField,
  AstTypeFields,
  AstVarDec,
  AstTypeArr,
  AstTypeSt,
  AstTypeInfo,
} ast_type;

struct ast_node;

// control statement
typedef union {
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
} ast_ctrlstmt;

typedef union {
  struct {
    struct ast_node *type;
    struct ast_node *size;
    struct ast_node *initval;
  } arraydef;
  struct {
    ast_node_t *typeid;
    ast_node_t *typeval;
  } typedec;
  struct {

  } typeval;
  struct {
    ast_node_t *ident;
    ast_node_t *typeid;
    ast_node_t *next;
  } typefields;
  struct {
    ast_node_t *ident;
  } typeid;
  struct {
    ast_node_t *ident;
    ast_node_t *typeid;
    ast_node_t *expr;
  } vardec
} ast_declist;

typedef union {
  struct {
    int count;
    int cap;
    struct ast_node **children;
  } fieldlist;
  struct {
    int count;
    int cap;
    struct ast_node **children;
  } exprlist;
  struct {
    int count;
    int cap;
    struct ast_node **children;
  } exprseq;
} ast_grpstmt;

typedef union {
  struct {
    yytoken_kind_t op;
    struct ast_node *left;
    struct ast_node *right;
  } binexpr;
  struct {
    yytoken_kind_t op;
    struct ast_node *val;
  } unexpr;
  struct {
    struct ast_node *var;
    struct ast_node *expr;
  } assexpr;
} ast_opstmt;

typedef union {
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
  } index;
  struct {
    yytoken_kind_t type;
    union {
      char *sval;
      int ival;
    };
  } rvalue;
} ast_valstmt;

typedef struct ast_node {
  ast_type type;
  union {
    ast_ctrlstmt ctrlstmt;
    ast_grpstmt grpstmt;
    ast_declist declist;
    ast_opstmt opstmt;
    ast_valstmt valstmt;
    struct {
      char *name;
      scope_t *sc;
    } ident;
    struct {
      struct ast_node *name;
      struct ast_node *fields;
    } st;
  };
} ast_node_t;

ast_node_t *ast_create_if(ast_node_t *cond, ast_node_t *then_expr,
                          ast_node_t *else_expr);
ast_node_t *ast_create_arraydef(ast_node_t *type, ast_node_t *size,
                                ast_node_t *initval);
ast_node_t *ast_create_exprseq();
void ast_append_exprseq(ast_node_t *cur, ast_node_t *src);
ast_node_t *ast_create_ident(char *name, scope_t *sc);
ast_node_t *ast_create_struct(ast_node_t *name, ast_node_t *fields);
ast_node_t *ast_create_fncall(ast_node_t *fnname, ast_node_t *params);
ast_node_t *ast_create_nil();
ast_node_t *ast_create_int(int ival);
ast_node_t *ast_create_string(const char *str);
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
ast_node_t *ast_create_fieldef(char *ident, ast_node_t *field);
ast_node_t *ast_create_fieldlist();
void ast_append_fieldlist(ast_node_t *cur, ast_node_t *src);
ast_node_t *ast_create_ident_index(ast_node_t *ident);
ast_node_t *ast_create_arr_index(ast_node_t *ival);
ast_node_t *ast_create_index(ast_node_t *val);
void ast_append_index(ast_node_t *cur, ast_node_t *next);
ast_node_t *ast_create_lvalue(ast_node_t *ident, ast_node_t *index);
ast_node_t *ast_create_typeid(yytoken_kind_t type, ast_node_t *ident);
ast_node_t *ast_create_typefield(ast_node_t *ident, ast_node_t *typeid);
ast_node_t *ast_create_typefields();
void ast_append_typefields(ast_node_t *cur, ast_node_t *src);
ast_node_t *ast_create_vardec(ast_node_t *ident, ast_node_t *typeid,
                              ast_node_t *expr);

#endif