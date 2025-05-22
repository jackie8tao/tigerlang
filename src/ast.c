#include <ast.h>
#include <stdlib.h>
#include <stuff.h>
#include <tigerdef.h>

#define AST_LIST_SIZE 5

#define ast_stmt_init(node_type, grp_name, field_name)                         \
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));                 \
  node->type = node_type;                                                      \
  node->grp_name.field_name.count = 0;                                         \
  node->grp_name.field_name.cap = AST_LIST_SIZE;                               \
  ast_node_t **subs =                                                          \
      (ast_node_t **)malloc(AST_LIST_SIZE * sizeof(ast_node_t *));             \
  node->grp_name.field_name.children = subs;                                   \
  return node;

#define ast_stmt_append(node_type, grp_name, field_name)                       \
  if (cur->type != node_type) {                                                \
    simple_msg("invalid node type");                                           \
    exit(ERR_ARGS);                                                            \
  }                                                                            \
  if (cur->grp_name.field_name.count >= cur->grp_name.field_name.cap) {        \
    int cap = cur->grp_name.field_name.cap + AST_LIST_SIZE;                    \
    ast_node_t **subs = (ast_node_t **)malloc(cap * sizeof(ast_node_t *));     \
    for (int i = 0; i < cur->grp_name.field_name.count; i++) {                 \
      subs[i] = cur->grp_name.field_name.children[i];                          \
    }                                                                          \
    free(cur->grp_name.field_name.children);                                   \
    cur->grp_name.field_name.children = subs;                                  \
  }                                                                            \
  cur->grp_name.field_name.children[cur->grp_name.field_name.count] = src;     \
  cur->grp_name.field_name.count++;

ast_node_t *ast_create_string(char *str) {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstString;
  node->valstmt.rvalue.type = TK_STRING;
  node->valstmt.rvalue.sval = str;
  return node;
}

ast_node_t *ast_create_int(int ival) {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstInt;
  node->valstmt.rvalue.type = TK_INTEGER;
  node->valstmt.rvalue.ival = ival;
  return node;
}

ast_node_t *ast_create_nil() {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstNil;
  return node;
}

ast_node_t *ast_create_binory(yytoken_kind_t op, ast_node_t *left,
                              ast_node_t *right) {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstBinory;
  node->opstmt.binexpr.op = op;
  node->opstmt.binexpr.left = left;
  node->opstmt.binexpr.right = right;
  return node;
}

ast_node_t *ast_create_unary(yytoken_kind_t op, ast_node_t *val) {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstUnary;
  node->opstmt.unexpr.op = op;
  node->opstmt.unexpr.val = val;
  return node;
}

ast_node_t *ast_create_assign(ast_node_t *var, ast_node_t *right) {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstAssign;
  node->opstmt.assexpr.var = var;
  node->opstmt.assexpr.expr = right;
  return node;
}

ast_node_t *ast_create_fncall(ast_node_t *fnname, ast_node_t *params) {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstFncall;
  node->ctrlstmt.fncall.fnname = fnname;
  node->ctrlstmt.fncall.params = params;
  return node;
}

ast_node_t *ast_create_struct(ast_node_t *name, ast_node_t *fields) {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstStruct;
  node->st.name = name;
  node->st.fields = fields;
  return node;
}

ast_node_t *ast_create_ident(char *name, scope_t *sc) {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstIdent;
  node->ident.name = name;
  node->ident.sc = sc;
  return node;
}

ast_node_t *ast_create_arraydef(ast_node_t *type, ast_node_t *size,
                                ast_node_t *initval) {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstArrDef;
  node->declist.arraydef.type = type;
  node->declist.arraydef.size = size;
  node->declist.arraydef.initval = initval;
  return node;
}

ast_node_t *ast_create_if(ast_node_t *cond, ast_node_t *thexpr,
                          ast_node_t *elexpr) {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstIf;
  node->ctrlstmt.ifexpr.cond = cond;
  node->ctrlstmt.ifexpr.elexpr = elexpr;
  node->ctrlstmt.ifexpr.thexpr = thexpr;
  return node;
}

ast_node_t *ast_create_while(ast_node_t *cond, ast_node_t *do_expr) {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstWhile;
  node->ctrlstmt.whexpr.cond = cond;
  node->ctrlstmt.whexpr.do_expr = do_expr;
  return node;
}

ast_node_t *ast_create_for(ast_node_t *itor, ast_node_t *start, ast_node_t *end,
                           ast_node_t *expr) {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstFor;
  node->ctrlstmt.forexpr.itor = itor;
  node->ctrlstmt.forexpr.start = start;
  node->ctrlstmt.forexpr.end = end;
  node->ctrlstmt.forexpr.expr = expr;
  return node;
}

ast_node_t *ast_create_let(ast_node_t *declist, ast_node_t *exprseq) {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstLet;
  node->ctrlstmt.letexpr.declist = declist;
  node->ctrlstmt.letexpr.exprseq = exprseq;
  return node;
}

ast_node_t *ast_create_exprseq() {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstExprSeq;
  node->grpstmt.exprseq.count = 0;
  node->grpstmt.exprseq.cap = AST_LIST_SIZE;
  ast_node_t **subs =
      (ast_node_t **)malloc(AST_LIST_SIZE * sizeof(ast_node_t *));
  node->grpstmt.exprseq.children = subs;
  return node;
}

void ast_append_exprseq(ast_node_t *cur, ast_node_t *src) {
  if (cur->type != AstExprSeq) {
    simple_msg("invalid node type");
    exit(ERR_ARGS);
  }
  if (cur->grpstmt.exprseq.count >= cur->grpstmt.exprseq.cap) {
    int cap = cur->grpstmt.exprseq.cap + AST_LIST_SIZE;
    ast_node_t **subs = (ast_node_t **)malloc(cap * sizeof(ast_node_t *));
    for (int i = 0; i < cur->grpstmt.exprseq.count; i++) {
      subs[i] = cur->grpstmt.exprseq.children[i];
    }
    free(cur->grpstmt.exprseq.children);
    cur->grpstmt.exprseq.children = subs;
  }
  cur->grpstmt.exprseq.children[cur->grpstmt.exprseq.count] = src;
  cur->grpstmt.exprseq.count++;
}

ast_node_t *ast_create_exprlist() {
  ast_stmt_init(AstExprList, grpstmt, exprlist);
}

void ast_append_exprlist(ast_node_t *cur, ast_node_t *src) {
  ast_stmt_append(AstExprList, grpstmt, exprlist);
}

ast_node_t *ast_create_fieldef(char *ident, ast_node_t *field) {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstFieldef;
  return node;
}

ast_node_t *ast_create_fieldlist() {
  ast_stmt_init(AstFieldList, grpstmt, fieldlist);
}

void ast_append_fieldlist(ast_node_t *cur, ast_node_t *src) {
  ast_stmt_append(AstFieldList, grpstmt, fieldlist);
}

ast_node_t *ast_create_ident_index(ast_node_t *ident) {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstIdentIndex;
  node->valstmt.index.ident_index = ident;
  return node;
}

ast_node_t *ast_create_arr_index(ast_node_t *ival) {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstArrIndex;
  node->valstmt.index.arr_index = ival;
  return node;
}

void ast_append_index(ast_node_t *cur, ast_node_t *next) {
  if (cur->type != AstArrIndex && cur->type != AstIdentIndex) {
    simple_msg("invalid node");
    exit(ERR_ARGS);
  }
  cur->valstmt.index.next = next;
}

ast_node_t *ast_create_lvalue(ast_node_t *ident, ast_node_t *index) {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstLvalue;
  node->valstmt.lvalue.ident = ident;
  node->valstmt.lvalue.index = index;
  return node;
}

ast_node_t *ast_create_typeid(yytoken_kind_t type, ast_node_t *ident) {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstTypeId;
  node->declist.typeid.ident = ident;
  return node;
}

ast_node_t *ast_create_typefield(ast_node_t *ident, ast_node_t *typeid) {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstTypeField;
  return node;
}

ast_node_t *ast_create_typefields(ast_node_t *ident, ast_node_t *typeid) {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstTypeFields;
  node->declist.typefields.ident = ident;
  node->declist.typefields.typeid = typeid;
  return node;
}

void ast_append_typefields(ast_node_t *cur, ast_node_t *src) {
  if (cur->type != AstTypeFields) {
    simple_msg("invalid node type");
    exit(ERR_ARGS);
  }
  while (cur->declist.typefields.next) {
    if (cur->type != AstTypeFields) {
      simple_msg("invalid node type");
      exit(ERR_ARGS);
    }
    cur = cur->declist.typefields.next;
  }
  cur->declist.typefields.next = src;
}

ast_node_t *ast_create_vardec(ast_node_t *ident, ast_node_t *typeid,
                              ast_node_t *expr) {
  ast_node_t *node = (ast_node_t *)malloc(sizeof(ast_node_t));
  node->type = AstVarDec;
  node->declist.vardec.ident = ident;
  node->declist.vardec.typeid = typeid;
  node->declist.vardec.expr = expr;
  return node;
}