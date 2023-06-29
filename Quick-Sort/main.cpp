#include <iostream>
#include <string.h>
#include <chrono>
#include <ctime>   
#include "func.h"

int main(int argc, char *argv[])
{
    std::vector<std::vector<int>> vetores;
    std::string escolhaPivo, particionamento;
    int tamanho, tipoParticionamento;
    
    srand (time(NULL));

    if (argc != 3)
    {
        std::cout << "Numero de parametros errado!" << std::endl;
        return 1; 
    }

    escolhaPivo = argv[1];
    particionamento = argv[2];

    if (particionamento.compare("lomuto") == 0)  //lomuto
        tipoParticionamento = 0;
    else if (particionamento.compare("hoare") == 0)
        tipoParticionamento = 1;
    else  //hoare
    {
        std::cout << "Tipo de particionamento errado!" << std::endl;
        return 2;
    }

    leArquivo(vetores);

    for(std::vector<int> &vetor : vetores)
    {
        tamanho = *vetor.begin();
        vetor.erase(vetor.begin());

        auto start = std::chrono::system_clock::now();

        if(escolhaPivo.compare("aleatorio") == 0) //random
                quickSortRandom(vetor, 0, tamanho - 1 ,tipoParticionamento);
        else //media de 3
                quickSortMedian(vetor, 0, tamanho - 1 ,tipoParticionamento);

        auto end = std::chrono::system_clock::now();

        std::chrono::duration<double> resultTime = end-start;

        std::cout << "TAMANHO ENTRADA " << tamanho << std::endl;
        std::cout << "SWAPS " << swapCounts << std::endl;
        std::cout << "RECURSOES " << recursionsCounts - 1 << std::endl;
        std::cout << "TEMPO " << resultTime.count() * 1000 << std::endl;
    }

    return 0;
}