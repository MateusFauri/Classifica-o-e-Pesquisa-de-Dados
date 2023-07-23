#include "hasing.h"

Hash::Hash(int sizeBucket)
{
  this->BUCKET = sizeBucket;
  this->emptyLists = 0;
  this->totalJogadores = 0;
  table = new std::list<Player>[BUCKET];
}

Hash::~Hash() {}

void Hash::insertItem(Player *player)
{
  int index = hashFunction(player->sofifa_id);

  table[index].push_back(*player);
  this->totalJogadores++;
}

int Hash::searchItem(int id, int *colisions) 
{
  std::list<Player>::iterator iter;
  int index = hashFunction(id);
  *colisions = 1;
  
  for (iter = table[index].begin(); iter != table[index].end(); iter++) 
  {
    if(iter->sofifa_id == id )
      return 1;
      
    (*colisions)++;
  }

  return 0;      
}

void Hash::sizeListsHash()
{
  int sum;

  for(int index = 0; index < this->BUCKET; index++)
  {
    sum = 0;

    if(table[index].empty())
    {
      this->emptyLists++;
      if(index == 0)
        this->minSizeList = this->maxSizeList = 0;
    }
    else
    {
      for(auto &list : table[index])
        sum++;

      if(index != 0)
      {
        if(sum < this->minSizeList)
          this->minSizeList = sum;
        if(sum > this->maxSizeList)
          this->maxSizeList = sum;
      }
      else
        this->minSizeList = this->maxSizeList = sum;
    }
  }
}

int Hash::hashFunction(int id) 
{
  return id % this->BUCKET;
}

int Hash::hashFunctionString(std::string word) 
{
  int value = 0;

  for (int caracter = 0; caracter < word.size(); caracter++)
    value += (word[caracter] + 5 * value) % this->BUCKET;

  return value % this->BUCKET;
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

void Hash::deleteItem(Player *player)
{
  std::list<Player>::iterator iter;
  int index = hashFunction(player->sofifa_id);

  for (iter = table[index].begin(); iter != table[index].end(); iter++) 
    if (iter->sofifa_id == player->sofifa_id)
      break;
  
  if (iter != table[index].end())
    table[index].erase(iter);
}