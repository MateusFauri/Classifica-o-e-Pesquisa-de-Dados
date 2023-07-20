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
    int max, min, sum, tamReal;

    max = vetor[0];
    min = vetor[0];
    sum = tamReal = 0;

    for(auto &element : vetor)
    {
        if(element > max)
            max = element;
        else if (element < min && element != 0)
            min = element;
        
        if(element != 0)
            tamReal++;
        sum += element;
    }

    std::cout << "MINIMO NUMERO DE TESTES POR NOME ENCONTRADO " << min << std::endl;
    std::cout << "MAXIMO NUMERO DE TESTES POR NOME ENCONTRADO " << max << std::endl;
    std::cout << "MEDIA NUMERO DE TESTES NOME ENCONTRADO " << (float) sum/tamReal << std::endl;
    std::cout << "MEDIA " << (float) sum / vetor.size() << std::endl;
}

int main(int argc, char** argv)
{
    std::ifstream file("consultas-fifa.txt");
    std::vector<Player> vetor;
    std::vector<int> tests;
    std::string id;
    int test, buckets;

    if (argc != 2)
        return 1;

    buckets = std::stoi(argv[1]);

    tokenize(",", vetor);

    Hash hash(buckets);

    for (auto &player : vetor)
        hash.insertItem(&player);

    //hash.displayHash();

    hash.sizeListsHash();

    std::cout << "NUMERO DE ENTRADAS DA TABELA USADAS " << buckets - hash.emptyLists << std::endl;
    std::cout << "NUMERO DE ENTRADAS DA TABELA VAZIAS " << hash.emptyLists << std::endl;
    std::cout << "TAXA DE OCUPACAO " << (float) (buckets - hash.emptyLists) / buckets << std::endl;
    std::cout << "MINIMO TAMANHO DE LISTA " << hash.minSizeList <<std::endl;
    std::cout << "MAXIMO TAMANHO DE LISTA " << hash.maxSizeList <<std::endl;
    std::cout << "MEDIO TAMANHO DE LISTA " << hash.totalJogadores / (buckets - hash.emptyLists)<< std::endl;

    while(getline(file, id))
    {
        if(!hash.searchItem(std::stoi(id), &test))
        {
            std::cout << std::stoi(id) << " MISS" << std::endl;
            test=0;
        }
        else
            std::cout << id << " HIT " << test <<  std::endl;

        tests.push_back(test);
    }

    get_max_and_min(tests);
}

