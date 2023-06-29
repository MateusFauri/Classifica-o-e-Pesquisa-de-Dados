#include <iostream>
#include <string.h>
#include <chrono>
#include <vector> 
#include <ctime>  
#include "radix.h"

void tokenize(std::string const &str, const char* delim, std::vector<std::string> &out) 
{ 
    char *token = strtok(const_cast<char*>(str.c_str()), delim); 
    while (token != nullptr) 
    { 
        out.push_back(std::string(token)); 
        token = strtok(nullptr, delim); 
    } 
} 
 

int main(int argc, char *argv[])
{
    std::string linha;
    std::vector<std::string> vetor;
    
    getline(std::cin, linha);
    tokenize(linha, " ", vetor);

    //print_vetor(vetor);

    vetor = radixSortMSD(vetor);

    std::cout << "Colocando o vetor acabado: ";
    print_vetor(vetor);
    
    return 0;
}

