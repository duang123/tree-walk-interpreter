#ifndef _TOKEN_H_
#define _TOKEN_H_

#include <string>

enum TokenType{
    // Single-character tokens.
  LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE,
  COMMA, DOT, MINUS, PLUS, SEMICOLON, SLASH, STAR,

  // One or two character tokens.
  BANG, BANG_EQUAL,
  EQUAL, EQUAL_EQUAL,
  GREATER, GREATER_EQUAL,
  LESS, LESS_EQUAL,

  // Literals.
  IDENTIFIER, STRING, NUMBER,

  // Keywords.
  AND, CLASS, ELSE, FALSE, FUN, FOR, IF, NIL, OR,
  PRINT, RETURN, SUPER, THIS, TRUE, VAR, WHILE,

  eof,
};

struct Token{
  TokenType type;
  std::string lexeme;
 // Object literal;
  int line;
  Token(TokenType type, const std::string& str, int line):type(type),lexeme(str),line(line){}
};

#endif
