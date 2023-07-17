#ifndef FUNCOES_H  
#define FUNCOES_H

#define POSITIONS 5

#include <iostream>
#include <math.h>
#include <stdlib.h>  
#include <list>
#include <string>

typedef struct
{
    int sofifa_id;
    std::string name;
    std::string positions[POSITIONS];
}Player;

class Hash
{
    int BUCKET;
    std::list<Player> *table;

public:
    Hash(int sizeBucket);  // Constructor
 
    void insertItem(Player *player);
    void deleteItem(Player *player);
    int hashFunction(std::string word);
    void displayHash();
};

#endif