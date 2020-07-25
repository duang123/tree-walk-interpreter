#include "astPrinter.h"
#include "expr.h"
#include "scanner.h"
#include <iostream>
#include <string>

static bool hadError = false;
static bool hadRuntimeError = false;
// static Interpreter interpreter;

static void report(int line, const std::string &where,
                   const std::string &message) {
  std::cout << "[line " << line << "] Error" << where << ": " << message
            << "\n";
  hadError = true;
}

// lox-error
static void error(int line, const std::string &message) {
  report(line, "", message);
}

// Parsing Expressions token-error
static void error(const Token &token, const std::string &message) {
  if (token.type == TokenType::eof) {
    report(token.line, " at end", message);
  } else {
    report(token.line, " at '" + token.lexeme + "'", message);
  }
}

// Evaluating Expressions runtime-error-method
/*
  static void runtimeError(RuntimeError error) {
    System.err.println(error.getMessage() +
        "\n[line " + error.token.line + "]");
    hadRuntimeError = true;
  }
  */

// run
static void run(const std::string &source) {
  Scanner scanner(source);
  auto tokens = scanner.scanTokens();
  // Scanning run < Parsing Expressions print-ast
  // For now, just print the tokens.
  for (Token token : tokens) {
    std::cout << token.type << "," << token.lexeme << "," << token.line << "\n";
  }
  // Parsing Expressions print-ast
  // Parser parser(tokens);
  /* Parsing Expressions print-ast < Statements and State parse-statements
      Expr expression = parser.parse();
  */
  //> Statements and State parse-statements
  // auto statements = parser.parse();
  //< Statements and State parse-statements

  // Stop if there was a syntax error.
  // if (hadError) return;

  //< Parsing Expressions print-ast
  //> Resolving and Binding create-resolver
  // Resolver resolver(interpreter);
  // resolver.resolve(statements);
  //> resolution-error

  // Stop if there was a resolution error.
  if (hadError)
    return;
  //< resolution-error

  //< Resolving and Binding create-resolver
  /* Parsing Expressions print-ast < Evaluating Expressions
     interpreter-interpret System.out.println(new
     AstPrinter().print(expression));
  */
  /* Evaluating Expressions interpreter-interpret < Statements and State
     interpret-statements interpreter.interpret(expression);
  */
  //> Statements and State interpret-statements
  // interpreter.interpret(statements);
  //< Statements and State interpret-statements
}
static void runPrompt() {

  for (;;) { // [repl]
    std::cout << "> ";
    std::string src;
    std::getline(std::cin, src);
    run(src);
    hadError = false;
  }
}
static void testAstPrinter(){
  Expr *expression = new Binary(
        new Unary(
            Token(MINUS, "-", 1),
            new Literal(123)),
        Token(STAR, "*", 1),
        new Grouping(
            new Literal(45.67)));

   AstPrinter astPrinter; 
   astPrinter.print(expression);
   std::cout<<"\n";
}

int main() { 
  /*runPrompt();*/
  testAstPrinter();
}
