#include "tokens.h"


Token::Token(TokenType type, std::string lexeme, int line)
	: m_type(type), m_lexeme(lexeme), m_line(line)
{}

//template <typename T>
Token::Token(TokenType type, std::string lexeme, int line, std::string value)
	: m_type(type), m_lexeme(lexeme), m_line(line), m_value(value)
{}