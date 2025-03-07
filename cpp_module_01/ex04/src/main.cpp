#include "replace_string.hpp"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <cstring>
#include <cerrno>

std::string read_file(char* path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "Error: " << std::strerror(errno) << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string text;
    std::string line;
    while (std::getline(file, line))
        text += line + "\n";
    file.close();

    return text;
}

void write_to_file(char *path, std::string text) {

    std::string new_filename = std::string(path) + ".replace";
    std::ofstream new_file(new_filename.c_str());
    if (!new_file.is_open()) {
        std::cerr << "Error: " << std::strerror(errno) << std::endl;
        exit(EXIT_FAILURE);
    }
    new_file << text;
    new_file.close();
}

int main(int argc, char *argv[]) {
    if (argc != 4)
        std::cerr << "Expect 3 arguments" << std::endl;

    std::string text = read_file(argv[1]);
    replace_string(text, std::string(argv[2]), std::string(argv[3]));
    write_to_file(argv[1], text);

    return 0;
}
