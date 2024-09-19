#include <fstream>

#include <iostream>
#include <algorithm>
//#include <boost/algorithm/string.hpp>

#include "scanner.h"
#include "tokens.h"
#include "lox.h"

int main(int argc, char* argv[]) {

    Lox lox;

    if (argc > 1)
        lox.runFile(argv[1]);
    

    lox.runPrompt();
    return 0;
}
