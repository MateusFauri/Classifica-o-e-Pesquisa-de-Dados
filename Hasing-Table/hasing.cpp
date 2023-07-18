#include "hasing.h"

Hash::Hash(int sizeBucket)
{
  this->BUCKET = sizeBucket;
  table = new std::list<Player>[BUCKET];
}

void Hash::insertItem(Player *player)
{
  int index = hashFunction(player->name);

  table[index].push_back(*player);
}
 
void Hash::deleteItem(Player *player)
{
  std::list<Player>::iterator iter;
  int index = hashFunction(player->name);

  for (iter = table[index].begin(); iter != table[index].end(); iter++) 
    if (iter->sofifa_id == player->sofifa_id)
      break;
  
  if (iter != table[index].end())
    table[index].erase(iter);
}
 
void Hash::displayHash() 
{
  std::list<Player>::iterator iter;
  
  for (int index = 0; index < this->BUCKET; index++) 
  {
    std::cout << index;

    for (iter = table[index].begin(); iter != table[index].end(); iter++) 
      std::cout << " --> " << iter->name;
      
    std::cout << std::endl;
  }
}

int Hash::searchItem(std::string name, int *tests) 
{
  std::list<Player>::iterator iter;
  int index = hashFunction(name);
  *tests = 1;
  
  for (iter = table[index].begin(); iter != table[index].end(); iter++) 
  {
    if(iter->name.compare(name) == 0 )
      return 1;
      
    (*tests)++;
  }
  return 0;      
}

int Hash::hashFunction(std::string word) 
{
  int value = 0;

  for (int caracter = 0; caracter < word.size(); caracter++)
    value += (word[caracter] + 5 * value) % this->BUCKET;

  return value % this->BUCKET;
}