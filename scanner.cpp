#include "scanner.h"
#include <cctype> 
#include <map> 
#include <iostream> 

static std::map<std::string, TokenType> keywords = {
	{"and",    AND},
	{"class",  CLASS},
	{"else",   ELSE},
	{"false",  FALSE},
	{"for",    FOR},
	{"fun",    FUN},
	{"if",     IF},
	{"nil",    NIL},
	{"or",     OR},
	{"print",  PRINT},
	{"return", RETURN},
	{"super",  SUPER},
	{"this",   THIS},
	{"true",   TRUE},
	{"var",    VAR},
	{"while",  WHILE},
};

void Scanner::identifier() {
    while (std::isalnum(peek())) advance();
    std::string text = source.substr(start, current - start);
    TokenType type;
    auto it = keywords.find(text);
    if (it == keywords.end()) type = IDENTIFIER;
    else type = it->second;
    addToken(type);
  }

char Scanner::peekNext() {
    if (current + 1 >= source.size()) return '\0';
    return source[current + 1];
  } 

void Scanner::number() {
    while (std::isdigit(peek())) advance();

    // Look for a fractional part.
    if (peek() == '.' && std::isdigit(peekNext())) {
      // Consume the "."
      advance();

      while (std::isdigit(peek())) advance();
    }

    //addToken(NUMBER, (source.substr(start, current)));
    tokens.push_back(Token(NUMBER, source.substr(start, current-start), line));
  }

 void Scanner::String() {
    while (peek() != '"' && !isAtEnd()) {
      if (peek() == '\n') line++;
      advance();
    }

    // Unterminated string.
    if (isAtEnd()) {
      std::cerr<<"line "<<line<< " meet unterminated string.\n";
      return;
    }

    // The closing ".
    advance();

    // Trim the surrounding quotes.
    std::string value = source.substr(start + 1, current - 2 - start);
    //addToken(STRING, value);
    tokens.push_back(Token(STRING, value, line));
}

char Scanner::peek() {
    if (isAtEnd()) return '\0';
    return source[current];
  }

char Scanner::advance() {
    current++;
    return source[current-1];
  }

void Scanner::addToken(TokenType type) {
	std::string text = source.substr(start, current-start);
    tokens.push_back(Token(type, text, line));
  }

bool Scanner::match(char expected) {
    if (isAtEnd()) return false;
    if (source[current] != expected) return false;

    current++;
    return true;
}

void Scanner::scanToken() {
    char c = advance();
    switch (c) {
      case '(': addToken(LEFT_PAREN); break;
      case ')': addToken(RIGHT_PAREN); break;
      case '{': addToken(LEFT_BRACE); break;
      case '}': addToken(RIGHT_BRACE); break;
      case ',': addToken(COMMA); break;
      case '.': addToken(DOT); break;
      case '-': addToken(MINUS); break;
      case '+': addToken(PLUS); break;
      case ';': addToken(SEMICOLON); break;
      case '*': addToken(STAR); break; 
      case '!': addToken(match('=') ? BANG_EQUAL : BANG); break;
      case '=': addToken(match('=') ? EQUAL_EQUAL : EQUAL); break;
      case '<': addToken(match('=') ? LESS_EQUAL : LESS); break;
      case '>': addToken(match('=') ? GREATER_EQUAL : GREATER); break;
      case '"': String(); break;
      case ' ':
      case '\r':
      case '\t':
        // Ignore whitespace.
        break;

      case '\n':
        line++;
        break;
      case '/':
        if (match('/')) {
          // A comment goes until the end of the line.
          while (peek() != '\n' && !isAtEnd()) advance();
        } else {
          addToken(SLASH);
        }
        break;
      default:
	if (isdigit(c)) {
          number();
        }else if (std::isalpha(c)) {
          identifier();
        } 
	else {
          std::cerr<<"line "<<line<< " meet unexpected character.\n";
        }
    }
}

std::vector<Token> Scanner::scanTokens(){
  while (!isAtEnd()) {
      // We are at the beginning of the next lexeme.
      start = current;
      scanToken();
      //char c = advance();
    }

    tokens.push_back(Token(eof, "eof", line));
    return tokens;
}
