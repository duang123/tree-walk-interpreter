#ifndef _AST_PRINTER_H_
#define _AST_PRINTER_H_

#include "expr.h"
#include "visitor.h"
#include <iostream>
#include <string>

class AstPrinter : public Visitor {
public:
  AstPrinter(){}
  virtual ~AstPrinter() {}
  void print(Expr *expr) { expr->accept(this); }
  virtual void visitBinaryExpr(Binary *expr) {
    parenthesize(expr->op.lexeme, expr->left, expr->right);
  }
  virtual void visitGroupingExpr(Grouping *expr) {
    parenthesize("group", expr->expression);
  }
  virtual void visitLiteralExpr(Literal *expr) { std::cout << expr->value; }
  virtual void visitUnaryExpr(Unary *expr) {
    parenthesize(expr->op.lexeme, expr->right);
  }

private:
  void parenthesize(std::string name, Expr *expr1, Expr *expr2) {
    std::cout << "(" << name;
    std::cout << " ";
    expr1->accept(this);
    std::cout << " ";
    expr2->accept(this);
    std::cout << ")";
  }
  void parenthesize(std::string name, Expr *expr) {
    std::cout << "(" << name;
    std::cout << " ";
    expr->accept(this);
    std::cout << ")";
  }
};

#endif
