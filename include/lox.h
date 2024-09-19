


#include "tokens.h"

#pragma once


class Lox {
    bool hadError = false;
public:
    Lox();
    void run(std::string source);
    void error(int line, std::string message);
    int runFile(std::string path);
    void runPrompt();

private:

    void report(int line, std::string where, std::string message) {
        std::cout << "[line " << line << "] Error" << where << ": " << message << std::endl;
        hadError = true;
    }
};