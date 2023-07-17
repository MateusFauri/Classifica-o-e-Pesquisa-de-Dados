#include <iostream>
#include <vector>
#include <string.h>
#include <fstream>
#include "hasing.h"

void tokenize(const char* delim, std::vector<Player> &out) 
{ 
    std::string line;
    Player player;
    char *token; 

    getline(std::cin, line);
    while(getline(std::cin, line))
    {
        //std::cout << line << std::endl;
        token = strtok(const_cast<char*>(line.c_str()), delim);
        while (token != nullptr)
        {
            std::cout << std::string(token) << " - ";
            token = strtok(nullptr, delim);
        }
        std::cout << std::endl;
    }

    /*strtok(const_cast<char*>(line.c_str()), delim)
    while (token != nullptr) 
    { 
        out.push_back(std::string(token)); 
        token = strtok(nullptr, delim); 
    } 
    */
} 

void print_vector(std::vector<Player> &vetor)
{
    for(auto player : vetor)
        std::cout << player.name << std::endl;
}

int main(int argc, char** argv)
{
    std::vector<Player> vetor;
    
    if (argc != 2)
        return 1;
    
    tokenize(",", vetor);
    //print_vector(vetor);


    /*
    Hash hash(std::stoi(argv[1]));

    for (auto name : vetor)
        hash.insertItem(name);

    hash.displayHash();

    hash.deleteItem(nome);

    std::cout << "Nova Hash" << std::endl;

    hash.displayHash();
    */
}

