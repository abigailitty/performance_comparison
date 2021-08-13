#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <list>
#include <iterator>

int main()
{
  std::list<int> list;
  list.push_back(3);
  list.push_back(4);
  list.push_back(5);

  for(typename std::list<int>::iterator itr = list.begin(); *itr != list.back(); itr++)
    std::cout << *itr << " " << *(std::next(itr, 1)) << " " << std::endl;

  return 0;
}