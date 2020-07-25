#ifndef _VISITOR_H_
#define _VISITOR_H_

class Binary;
class Grouping;
class Literal;
class Unary;

class Visitor {
public:
  virtual void visitBinaryExpr(Binary *expr)=0;
  virtual void visitGroupingExpr(Grouping *expr)=0;
  virtual void visitLiteralExpr(Literal *expr)=0;
  virtual void visitUnaryExpr(Unary *expr)=0;
  virtual ~Visitor() {}
  /*
  virtual void visitAssignExpr(Assign *expr);
  virtual void visitCallExpr(Call *expr);
  virtual void visitGetExpr(Get *expr);
  virtual void visitLogicalExpr(Logical *expr);
  virtual void visitSetExpr(Set *expr);
  virtual void visitSuperExpr(Super *expr);
  virtual void visitThisExpr(This *expr);
  virtual void visitVariableExpr(Variable *expr);
  */
};

#endif
