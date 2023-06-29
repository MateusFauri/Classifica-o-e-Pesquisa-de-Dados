#ifndef FUNCOES_H  // Guarda de inclus�o para evitar m�ltiplas inclus�es
#define FUNCOES_H
#include <iostream>
#include <vector>
#include <stdlib.h>     
#include <time.h>       
#include <cmath>
#include <sstream>

extern int swapCounts;
extern int recursionsCounts;


void printVector(std::vector<int>& vector);

// Troca a posicão 1 pela posicão 2 do vetor lista
void swap(std::vector<int>& lista, int posicao1, int posicao2);

// cria um vetor de vetores com as entradas do arquivo
void leArquivo(std::vector<std::vector<int>> &vetores);

// retorna a posicao da mediana dos 3 valores (inicio, meio, fim)
int medianaTres(std::vector<int>& lista, int inicio, int fim);

// faz o quicksort usando a mediana
void quickSortMedian(std::vector<int>& lista, int inicio, int fim, int particionamento);

// faz o quicksort usando um pivo aleatorio
void quickSortRandom(std::vector<int>& lista, int inicio, int fim, int particionamento);

// faz o particionamento da forma Hoare 
int partitionHoare(std::vector<int>& vector, int left, int right);
// faz o particionamento da forma lomuto
int partitionLomuto(std::vector<int>& vector, int left, int right);

#endif