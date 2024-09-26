#include <iostream>

#include "scanner.h"
#include "tokens.h"


Scanner::Scanner(std::string source)
	: m_source(source),
	start{ 0 },
	current{ 0 },
	line{ 1 }
{}

char Scanner::advance() {
	return m_source[current++];
}

bool Scanner::match(char expected) {
	if (isAtEnd()) return false;
	if (m_source[current] != expected) return false;

	current++;
	return true;
}

char Scanner::peek() {
	if (isAtEnd()) return '\0';
	return m_source[current];
}

void Scanner::string() {
	std::cout << "exec" << std::endl;
	while (peek() != '"' && !isAtEnd()) {
		if (peek() == '\n') 
			line++;
		advance();
	}

	if (isAtEnd()) {
		m_lox.error(line, "Unterminated string");
	}

	advance();
	std::string str = m_source.substr(start+1, (current - start)-2);
	addToken(STRING, str);
}

bool Scanner::isAtEnd() {
	return current >= m_source.length();
}

std::vector<Token> Scanner::scanTokens() {
	while (!isAtEnd()) {
		start = current;
		scanToken();
	}
	m_tokens.push_back(Token(_EOF, "", line));
	return m_tokens;
}


void Scanner::addToken(TokenType type) {
	std::string text = m_source.substr(start, current-start);
	Token token(type, text, line);
	m_tokens.push_back(token);
	
}

template<typename T>
void Scanner::addToken(TokenType type, T value) {
	std::cout << "added " << value << std::endl;
	std::string text = m_source.substr(start, current - start);
	Token token(type, text, line, value);
	m_tokens.push_back(token);

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
	case '!':
		addToken(match('=') ? BANG_EQUAL : BANG);
		break;
	case '=':
		addToken(match('=') ? EQUAL_EQUAL : EQUAL);
		break;
	case '<':
		addToken(match('=') ? LESS_EQUAL : LESS);
		break;
	case '>':
		addToken(match('=') ? GREATER_EQUAL : GREATER);
		break;
	case '/':
		if (match('/')) {
			while (peek() != '\n' && !isAtEnd()) 
				advance();
		}
		else {
			addToken(SLASH);
		}
		break;
	case ' ':
	case '\r':
	case '\t':
		break;
	case '\n':
		line++;
		break;
	case '"':
		string();
		break;


	default:
		
		std::string err = "Unexpected character: ";
		err.push_back(c);
		m_lox.error(line, err);
		break;
	}
	
}

