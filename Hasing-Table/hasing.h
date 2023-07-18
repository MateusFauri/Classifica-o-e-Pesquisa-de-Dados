#ifndef FUNCOES_H  
#define FUNCOES_H

#define POSITIONS 5

#include <iostream>
#include <math.h>
#include <stdlib.h>  
#include <list>
#include <vector>
#include <string>

typedef struct
{
    int sofifa_id;
    std::string name;
    std::vector<std::string> positions;
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
    int searchItem(std::string name, int *tests);
    void displayHash();
    
};

#endif