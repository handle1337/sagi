#include <vector>
#include <iostream>
#include "lox.h"


#pragma once

class Scanner {
	Lox m_lox;
	std::string m_source;
	std::vector<Token> m_tokens{};
	int start, current, line;
	
public:
	Scanner(std::string source);
	std::vector<Token> scanTokens();
private:
	
	char advance();
	bool match(char expected);
	char peek();
	void string();
	bool isAtEnd();

	void addToken(TokenType type);
	template<typename T> void addToken(TokenType type, T value = T());



	void scanToken();
	
};