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
	void addToken(TokenType type);
	void scanToken();
	

	bool isAtEnd() {
		return current >= m_source.length();
	}
};