#include <iostream>
#include <fstream>
#include <string>

#include "scanner.h"



std::ostream& operator<<(std::ostream& os, Token& token) {
    return os << "Lexeme: " << token.m_lexeme << " type: " << token.m_type 
        << " Literal: " << token.m_value << std::endl;
}

Lox::Lox() {};

void Lox::run(std::string source) {
    Scanner scanner(source);

    std::vector<Token> tokens = scanner.scanTokens();
    for (auto& token : tokens) {
        std::cout << token;
    }
    std::cout << "";
}

void Lox::error(int line, std::string message) {
    report(line, "", message);
}

int Lox::runFile(std::string path) {
    std::ifstream inFile{ path };
    if (!inFile) {
        std::cerr << "Can't open file";
        return 1;
    }

    std::string strInput{};
    while (inFile >> strInput) {
        run(strInput);
        if (hadError) exit(65);
    }
    return 0;
}

void Lox::runPrompt() {

    std::string input{};
    while (true)
    {
        std::getline(std::cin, input);
        run(input);
        hadError = false;
        std::cout << "\n";

    }
}