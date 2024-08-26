#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <print>
#include <boost/algorithm/string.hpp>

using VectToken = std::vector<std::string>;


struct Scanner {

    void run(std::string source) {
        VectToken tokens = tokenize(source);
        for (auto &token : tokens) {
            std::cout << token + " ";
        }
        std::cout << "";
    }

    VectToken tokenize(std::string string) {
        VectToken tokens {};
        boost::algorithm::split(tokens, string, boost::is_any_of(" "));
        return tokens;
    }
};



int runFile(std::string path) {
    std::ifstream inf{path};
    if (!inf) {
        std::cerr << "Can't open file";
        return 1;
    }

    std::string strInput{};
    while (inf >> strInput) {
        std::cout << strInput << '\n';
    }
}

void runPrompt() {

    Scanner scanner;
    std::string input {};
    while (true)
    {
        std::getline(std::cin, input);
        scanner.run(input);
        std::cout << "\n";

    }
}

int main(){
    Scanner scanner;

    runPrompt();
    return 0;
}
