#include <fstream>
#include <iostream>


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
    std::string input {};
    while (true)
    {
        std::cout << "\n>>";
        std::cin >> input;
        std::cout << input;
    }
}

int main(){
    runPrompt();
    return 0;
}
