#pragma once

#include <iostream>
#include <any>


enum TokenType
{
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

    _EOF
};

class Token {
public:
   
    Token(TokenType type, std::string lexeme, int line);
    Token(TokenType type, std::string lexeme, int line, std::string value);
private:
    friend std::ostream& operator<<(std::ostream& os, Token& token);
    TokenType m_type = TokenType::_EOF;
    std::string m_lexeme{};
    int m_line{};
    std::string m_value;
};