#ifndef _EXPR_H_
#define _EXPR_H_

#include "token.h"
#include "visitor.h"
#include "astPrinter.h"

class Expr {
public:
  virtual ~Expr() {}
  virtual void accept(Visitor *v) = 0;
};
/*
class Assign : public Expr {
public:
    Assign(Token name, Expr value):name(name),value(value) {}

    accept(Visitor* visitor) {
      return visitor->visitAssignExpr(this);
    }
private:
    Token name;
    Expr* value;
};
*/
class Binary : public Expr {
  friend class AstPrinter;

public:
  Binary(Expr *left, const Token &op, Expr *right)
      : left(left), op(op), right(right) {}

  void accept(Visitor *visitor) { visitor->visitBinaryExpr(this); }

private:
  Expr *left;
  Token op;
  Expr *right;
};
/*
  static class Call extends Expr {
    Call(Expr callee, Token paren, List<Expr> arguments) {
      this.callee = callee;
      this.paren = paren;
      this.arguments = arguments;
    }

    @Override
    <R> R accept(Visitor<R> visitor) {
      return visitor.visitCallExpr(this);
    }

    final Expr callee;
    final Token paren;
    final List<Expr> arguments;
  }
  static class Get extends Expr {
    Get(Expr object, Token name) {
      this.object = object;
      this.name = name;
    }

    <R> R accept(Visitor<R> visitor) {
      return visitor.visitGetExpr(this);
    }

    final Expr object;
    final Token name;
  }
  */

class Grouping : public Expr {
  friend class AstPrinter;

public:
  Grouping(Expr *expression) : expression(expression) {}

  void accept(Visitor *visitor) { visitor->visitGroupingExpr(this); }

private:
  Expr *expression;
};

class Literal : public Expr {
  friend class AstPrinter;

public:
  Literal(double value) : value(value) {}

  void accept(Visitor *visitor) { visitor->visitLiteralExpr(this); }

private:
  double value;
};
/*
  static class Logical extends Expr {
    Logical(Expr left, Token operator, Expr right) {
      this.left = left;
      this.operator = operator;
      this.right = right;
    }

    @Override
    <R> R accept(Visitor<R> visitor) {
      return visitor.visitLogicalExpr(this);
    }

    final Expr left;
    final Token operator;
    final Expr right;
  }
//< expr-logical
//> expr-set
  static class Set extends Expr {
    Set(Expr object, Token name, Expr value) {
      this.object = object;
      this.name = name;
      this.value = value;
    }

    @Override
    <R> R accept(Visitor<R> visitor) {
      return visitor.visitSetExpr(this);
    }

    final Expr object;
    final Token name;
    final Expr value;
  }
//< expr-set
//> expr-super
  static class Super extends Expr {
    Super(Token keyword, Token method) {
      this.keyword = keyword;
      this.method = method;
    }

    @Override
    <R> R accept(Visitor<R> visitor) {
      return visitor.visitSuperExpr(this);
    }

    final Token keyword;
    final Token method;
  }
//< expr-super
//> expr-this
  static class This extends Expr {
    This(Token keyword) {
      this.keyword = keyword;
    }

    @Override
    <R> R accept(Visitor<R> visitor) {
      return visitor.visitThisExpr(this);
    }

    final Token keyword;
  }
  */

class Unary : public Expr {
  friend class AstPrinter;

public:
  Unary(const Token &op, Expr *right) : op(op), right(right) {}
  void accept(Visitor *visitor) { visitor->visitUnaryExpr(this); }
private:
  Token op;
  Expr *right;
};
/*
  static class Variable extends Expr {
    Variable(Token name) {
      this.name = name;
    }

    @Override
    <R> R accept(Visitor<R> visitor) {
      return visitor.visitVariableExpr(this);
    }

    final Token name;
  }

  abstract <R> R accept(Visitor<R> visitor);
*/
#endif
