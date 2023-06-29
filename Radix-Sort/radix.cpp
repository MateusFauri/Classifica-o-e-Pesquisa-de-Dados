#include "radix.h"

void insertionSort(std::vector<std::string>& vetor, int index)
{
    print_vetor(vetor);

    for (int chave = 1; chave < vetor.size(); chave++)
    {
        std::string escolhido = vetor[chave];
        int auxiliar = chave - 1;

        while ((auxiliar >= 0) && (int(vetor[auxiliar][index]) > int(escolhido[index])))
        {
            vetor[auxiliar + 1 ] = vetor[auxiliar];
            auxiliar--;
        }
        
        vetor[auxiliar + 1] = escolhido;
    }

    print_vetor(vetor);
}

std::vector<std::string>& radixSortMSD(std::vector<std::string>& vetor)
{
    std::vector<std::string> auxiliar;
    return msd(vetor, 0, auxiliar);
}

std::vector<std::string>& msd(std::vector<std::string>& vetor, int index, std::vector<std::string>& auxiliar)
{
    if (index >= vetor[0].length() || vetor.size() <= 1)
        return vetor;

    int inicio = 0;

    std::vector<std::string> final;
    std::cout << "Index: " << index << std::endl;
    insertionSort(vetor, index);

    for(int fim = 1; fim <= vetor.size(); fim++)
    {
        std::cout << "Inicio: " << inicio << " Fim: "<< fim << " Tamanho: "<< vetor.size() << std::endl;

        if(fim == vetor.size() || vetor[inicio][index] != vetor[fim][index])
        {
            std::cout << "Entrou Aqui!" << std::endl;
            std::vector<std::string> sublist;
            std::copy(vetor.begin() + inicio, vetor.begin() + fim , std::back_inserter(sublist));
            for(std::string &string : msd(sublist, index + 1, auxiliar))
                final.push_back(string);

            inicio = fim;
        }
    }

    std::cout << "Vetor final: ";
    print_vetor(final);
    auxiliar = final;
    return auxiliar;
}

void print_vetor(std::vector<std::string>& vetor)
{
    for(auto &string : vetor)
        std::cout << string << " " ;
    
    std::cout << std::endl;
}