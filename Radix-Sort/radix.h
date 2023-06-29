#ifndef FUNCOES_H  // Guarda de inclus�o para evitar m�ltiplas inclus�es
#define FUNCOES_H
#include <iostream>
#include <vector>
#include <stdlib.h>     
#include <time.h>       
#include <stack>         

void insertionSort(std::vector<std::string>& vetor, int index);
std::vector<std::string>& radixSortMSD(std::vector<std::string>& vetor);
std::vector<std::string>& msd(std::vector<std::string>& vetor, int index, std::vector<std::string>& auxiliar);

void print_vetor(std::vector<std::string>& vetor);

#endif