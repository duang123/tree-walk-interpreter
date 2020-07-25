#ifndef _SCANNER_H_
#define _SCANNER_H_

#include "token.h"
#include <vector>

class Scanner {
  std::string source;
  std::vector<Token> tokens;
  int start = 0;
  int current = 0;
  int line = 1;
  bool isAtEnd() { return current >= source.size(); }
  void identifier();
  char peekNext();
  void number();
  void String();
  char peek();
  char advance();
  void addToken(TokenType type);
  bool match(char expected);
  void scanToken();

public:
  Scanner(const std::string &source) : source(source) {}
  std::vector<Token> scanTokens();
};

#endif
