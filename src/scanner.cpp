#include <iostream>

#include "scanner.h"
#include "tokens.h"



Scanner::Scanner(std::string source)
	: m_source(source),
	start(0), //set to 0
	current{ 0 },
	line(1)
{}

std::vector<Token> Scanner::scanTokens() {
	while (!isAtEnd()) {
		start = current;
		scanToken();
	}
	m_tokens.push_back(Token(_EOF, "", line));
	return m_tokens;
}


char Scanner::advance() {
	return m_source[current++];
}

void Scanner::addToken(TokenType type) {
	std::cout << m_source << std::endl;
	std::string text = m_source.substr(start, 1); //TODO: set lenght param to current
	std::cout << text << "s" << start << "c" << current << std::endl;
	m_tokens.push_back(Token(type, text, line));
}

void Scanner::scanToken()
{
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
	case '*': addToken(STAR); break;
	case ';': addToken(SEMICOLON); break;
	default:
		m_lox.error(line, "Unexpected character");
		break;
	} 
	start++;//TODO: comment this

}

