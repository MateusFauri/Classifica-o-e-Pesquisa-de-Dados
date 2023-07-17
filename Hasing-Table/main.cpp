#include <iostream>
#include <vector>
#include <string.h>
#include <fstream>
#include "hasing.h"

void tokenize(const char* delim, std::vector<Player> &out) 
{ 
    std::vector<std::string> positions;
    std::string line;
    Player player;
    char *token; 

    getline(std::cin, line);
    while(getline(std::cin, line))
    {
        token = strtok(const_cast<char*>(line.c_str()), delim);

        if(token != nullptr)
        {
            player.sofifa_id = std::stoi(token);
            token = strtok(nullptr, delim);

            player.name = std::string(token);
            token = strtok(nullptr, delim);

            while (token != nullptr)
            {
                positions.push_back(std::string(token));
                token = strtok(nullptr, delim);
            }

            player.positions = positions;
            out.push_back(player);
            positions.clear();
        }

    }
} 

void print_vector(std::vector<Player> &vetor)
{
    for(auto player : vetor)
        std::cout << player.name << " - " << player.sofifa_id << std::endl;
}

int main(int argc, char** argv)
{
    std::vector<Player> vetor;
    
    if (argc != 2)
        return 1;
    
    tokenize(",", vetor);

    Hash hash(std::stoi(argv[1]));

    for (auto player : vetor)
        hash.insertItem(&player);

    hash.displayHash();

    std::cout << "Procurando por uma pessoa..." << std::endl;

    if(!hash.searchItem(std::string("Lionel Messi Cuccittini")))
        std::cout << "Não foi achado tal pessoa..." << std::endl;


/*
    hash.deleteItem(nome);

    std::cout << "Nova Hash" << std::endl;

    hash.displayHash();
*/
}

