
#pragma once

#include <vector>
#include <iostream>

#include "lox.h"



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
	bool match(std::string expected);
	char peek();
	void string(bool multiLine=false);
	bool isAtEnd();

	void addToken(TokenType type);
	template<typename T> void addToken(TokenType type, T value);



	void scanToken();
	
};