#include "hasing.h"

Hash::Hash(int sizeBucket)
{
  this->BUCKET = sizeBucket;
  table = new std::vector<std::list<std::string>>[BUCKET];
}

void Hash::insertItem(std::string word)
{
  std::vector<std::list<std::string>>::iterator iter;
  int index = hashFunction(word);

  (*table)[index].push_back(word);
}
 
void Hash::deleteItem(std::string word)
{
  std::list<std::string>::iterator iter;
  int index = hashFunction(word);

  for (iter = (*table)[index].begin(); iter != (*table)[index].end(); iter++) 
    if (*iter == word)
      break;
  
  if (iter != (*table)[index].end())
    (*table)[index].erase(iter);
}
 
void Hash::displayHash() 
{
  std::list<std::string>::iterator iter;
  for (int index = 0; index < BUCKET; index++) 
  {
    std::cout << index;
    iter = (*table)[index].begin();

    for (iter = (*table)[index].begin(); iter != (*table)[index].end(); iter++) 
      std::cout << " --> " << *iter;
      
    std::cout << std::endl;
  }
}


int Hash::hashFunction(std::string word) 
{
  int value = 0;

  for (int caracter = 0; caracter < word.size(); caracter++)
    value += (word[caracter] + 5 * value) % this->BUCKET;

  return value;
}