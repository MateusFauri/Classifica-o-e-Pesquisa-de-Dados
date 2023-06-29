#include "func.h"

int swapCounts = 0;
int recursionsCounts = 0;

void printVector(std::vector<int>& vector)
{
    for(auto number : vector)
        std::cout << number << ' ';
    std::cout << std::endl;
}

void leArquivo(std::vector<std::vector<int>> &vetores)
{
    //Le arquivo linha por linha
    std::string linha;

    while ((getline(std::cin, linha)))
    {
        std::vector<int> vetor;
        std::istringstream iss(linha);
        int numero;

        //Formata cada caracter da string em número inteiro
        while(iss >> numero)
        {
            //Posiciona o valor já formatado no final do vetor
            vetor.push_back(numero);
        }

        //Posiciona o vetor construído acima no final de um vetor (de vetores)
        vetores.push_back(vetor);
    }

}

int medianaTres(std::vector<int>& lista, int inicio, int fim)
{
    int inicioValor, fimValor, medio, pivo;

    inicioValor = lista[inicio];
    fimValor = lista[fim];
    medio = lista[floor(fim-inicio)];

    if(inicioValor < medio)
    {
        if (medio < fim)
            pivo = floor(fim-inicio);
        else
            if (inicioValor < fimValor)
                pivo = fim;
            else
                pivo = inicio;
    }
    else
    {
        if (fimValor < medio)
            pivo = floor(fim-inicio);
        else
            if (fimValor < inicioValor)
                pivo = fim;
            else
                pivo = inicio;
    }

    return pivo;
}

void swap(std::vector<int>& lista, int posicao1, int posicao2)
{
    int auxiliar;

    auxiliar = lista[posicao1];
    lista[posicao1] = lista[posicao2];
    lista[posicao2] = auxiliar;

    swapCounts++;
}

void quickSortMedian(std::vector<int>& lista, int inicio, int fim, int particionamento)
{
    int median,pivo;

    if (fim > inicio)
    {
        recursionsCounts++;
        median = medianaTres(lista, inicio, fim);
        swap(lista, inicio, median);

        if (particionamento == 0) 
            pivo = partitionLomuto(lista, inicio, fim);
        else 
            pivo = partitionHoare(lista, inicio, fim);

        quickSortMedian(lista, inicio, pivo - 1, particionamento);
        quickSortMedian(lista, pivo + 1, fim, particionamento);
    }   
}

void quickSortRandom(std::vector<int>& lista, int inicio, int fim, int particionamento)
{
    int random, pivo;

    if ( fim > inicio)
    {
        recursionsCounts++;
        random = rand() % (fim - inicio + 1) + inicio;
        swap(lista, inicio, random);

        if (particionamento == 0) 
            pivo = partitionLomuto(lista, inicio, fim);
        else 
            pivo = partitionHoare(lista, inicio, fim);
        
        quickSortRandom(lista, inicio, pivo - 1, particionamento);
        quickSortRandom(lista, pivo + 1, fim, particionamento);
    }   
}

int partitionLomuto(std::vector<int>& vector, int left, int right)
{
    int key = vector[left];
    int storeIndex = left + 1;

    for (int count = left+1; count <= right; count++)
    {
        if (vector[count] < key)
        {
            swap(vector, count, storeIndex);
            storeIndex++;
        }
    }
    swap(vector, left, storeIndex - 1);

    return storeIndex - 1;
}

int partitionHoare(std::vector<int>& vector, int left, int right)
{
    int key, newLeft, newRight;
    key = vector[left];
    newLeft = left;
    newRight = right;

    while ( newLeft < newRight )
    {
        while (vector[newRight] > key && newLeft < newRight)
            newRight--;
        vector[newLeft] = vector[newRight];

        while ( vector[newLeft] <= key && newLeft < newRight )
            newLeft++;
        vector[newRight] = vector[newLeft];        
    }
    vector[newRight] = key;
    return newLeft;
}
