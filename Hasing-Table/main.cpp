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

void get_max_and_min(std::vector<int> &vetor)
{
    int max, min;

    max = vetor[0];
    min = vetor[0];

    for(auto element : vetor)
    {
        if(element > max)
            max = element;
        else if (element < min && element != 0)
            min = element;
    }

    std::cout << "MINIMO NUMERO DE TESTES POR NOME ENCONTRADO " << min << std::endl;
    std::cout << "MAXIMO NUMERO DE TESTES POR NOME ENCONTRADO " << max << std::endl;
}

int main(int argc, char** argv)
{
    std::ifstream file("consulta.txt");
    std::vector<Player> vetor;
    std::vector<int> tests;
    std::string name;
    int test;

    if (argc != 2)
        return 1;
    
    tokenize(",", vetor);

    Hash hash(std::stoi(argv[1]));

    for (auto player : vetor)
        hash.insertItem(&player);

    hash.displayHash();

    while(getline(file, name))
    {
        if(!hash.searchItem(name, &test))
        {
            std::cout << name << " MISS" << std::endl;
            test=0;
        }
        else
            std::cout << name << " HIT " << test <<  std::endl;

        tests.push_back(test);
    }

    get_max_and_min(tests);
}

