#include <MyArgParser.h>
#include <iostream>

int main(int argc, char* argv[]) {
    yyang::ArgParser parser(argc, argv);

    std::string name = parser.getStr("--name", "Guest");
    int age = parser.getInt("--age", 0);
    bool verbose = parser.getFlag("--verbose");

    std::cout << "Name: " << name << "\n";
    std::cout << "Age: " << age << "\n";
    std::cout << "Verbose mode: " << (verbose ? "ON" : "OFF") << "\n";

    return 0;
}