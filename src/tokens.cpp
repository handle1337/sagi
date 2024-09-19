#include "tokens.h"

//template <typename T>
Token::Token(TokenType type, std::string lexeme, int line)
	: m_type(type), m_lexeme(lexeme), m_line(line)
{}