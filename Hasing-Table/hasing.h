#ifndef FUNCOES_H  
#define FUNCOES_H

#include <iostream>
#include <vector>
#include <math.h>
#include <stdlib.h>  
#include <list>
#include <vector>
#include <string>

class Hash
{
    int BUCKET;
    std::vector<std::list<std::string>> *table;

public:

    Hash(int sizeBucket);  // Constructor
 
    void insertItem(std::string word);
    void deleteItem(std::string word);
    int hashFunction(std::string word);
    void displayHash();
};

#endif