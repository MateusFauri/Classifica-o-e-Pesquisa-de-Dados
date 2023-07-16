#include <iostream>
#include <string.h>
#include "hasing.h"

void tokenize(std::string &str, const char* delim, std::vector<std::string> &out) 
{ 
    char *token = strtok(const_cast<char*>(str.c_str()), delim); 
    while (token != nullptr) 
    { 
        out.push_back(std::string(token)); 
        token = strtok(nullptr, delim); 
    } 
} 

void print_vector(std::vector<std::string> &vetor)
{
    for(auto name : vetor)
        std::cout << name << std::endl;
}

int main(int argc, char** argv)
{
    std::vector<std::string> vetor;
    std::string linha;
    
    if (argc != 2)
        return 1;
    
    while(std::getline(std::cin, linha))
        tokenize(linha, "\n", vetor);

    Hash hash(std::stoi(argv[1]));

    for (auto name : vetor)
        hash.insertItem(name);

    hash.displayHash();
}

