#include <cassert>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <iterator>


// defined in performance.cpp
void usage();

template <class T>
void hash_mode(std::unordered_map<T, int> &ht, std::ostream &ostr, int &output_count)
{
	T mode = ht.begin()->first;
	int mode_count = ht.begin()->second;
	for(typename std::unordered_map<T, int>::iterator itr = ht.begin(); itr != ht.end(); itr++)
	{
        if(itr->second > mode_count)
        {
        	mode = itr->first;
        	mode_count = itr->second;
        }
	}

	output_count = 1;
	ostr << mode << std::endl;
}

//only ints
void hash_closest_pair(std::unordered_map<int, int> &ht, std::ostream &ostr, int &output_count){
  assert (ht.size() >= 2);
  
  int first = ht.begin()->first;
  int second = ht.begin()->first;
  int best = 10000;

  for(typename std::unordered_map<int, int>::iterator itr1 = ht.begin(); itr1 != ht.end(); itr1++)
  	for(typename std::unordered_map<int, int>::iterator itr2 = std::next(itr1, 1); itr2 != ht.end(); itr2++)
  	{
  		if(abs(itr1->first - itr2->first) < best)
  		{
  			first = itr1->first;
  			second = itr2->first;
  			best = abs(itr1->first - itr2->first);
  		}
  	}

  // print the two elements
  output_count = 2;
  ostr << first << "\n";
  ostr << second << "\n";
}

void hash_longest_substring(std::unordered_map<std::string, int> &ht, std::ostream &ostr, int &output_count){
  assert(ht.size() >= 2);
  std::string longest = "";
  for(typename std::unordered_map<std::string, int>::iterator itr = ht.begin(); itr != ht.end(); itr++) //word
    for(int j = 0; j < int((itr->first).size()); j++) //all characters in word
      for(typename std::unordered_map<std::string, int>::iterator itr2 = std::next(itr, 1); itr2 != ht.end(); itr2++) //comparison word (all words after current word)
        for(int l = 0; l < int((itr2->first).size()); l++) //all character in each comparison word
        {
          if(itr->first != itr2->first && itr->first[j] == itr2->first[l])
          {
            std::string temp = "";
            int first_index = j;
            int second_index = l;

            while(first_index < int(itr->first.size()) && second_index < int(itr2->first.size()) &&
                  itr->first[first_index] == itr2->first[second_index])
            {
              temp += itr->first[first_index];
              first_index++;
              second_index++;
            }

            if(temp.size() > longest.size())
              longest = temp;
          }
        }
  output_count = 1;
  ostr << longest << std::endl;
}

void hash_table_test(const std::string &operation, const std::string &type,
                     std::istream &istr, std::ostream &ostr,
                     int &input_count, int &output_count, int optional_arg) {

  // HINT: For the string element type, declare your hash table like this:
  // std::unordered_set<std::string> ht;
  // OR 
  // std::unordered_map<std::string,int> ht;

  if(type == "string")
  {
  	//build unordered map
  	std::unordered_map<std::string, int> ht;
  	if(operation != "remove_duplicates")
  	{
		std::string str;
	  	while(istr >> str)
	  	{
	  		ht[str]++;
	  		input_count++;
	  	}
  	}
  	
  	

  	//operations
  	if(operation == "sort")
  		std::cout << "it is not feasible/sensible to use operation with this data structure" << std::endl;
  	else if(operation == "remove_duplicates")
  	{
  		std::string str;
	  	while(istr >> str)
	  	{
	  		input_count++;
	  		if(ht[str] == 0)
	  		{
	  			ostr << str << std::endl;
	  			output_count++;
	  		}
	  		ht[str]++;
	  	}
  	}
  	else if(operation == "mode")
  		hash_mode(ht, ostr, output_count);
  	//no "closest_pair" for strings
  	else if(operation == "first_sorted")
  		std::cout << "it is not feasible/sensible to use operation with this data structure" << std::endl;
  	else if(operation == "longest_substring")
  		hash_longest_substring(ht, ostr, output_count);
  	else{
  		std::cerr << "Error: Unknown operation: " << operation << std::endl; 
  		usage();
  		exit(0);
  	}
  }
  else
  {
  	//build unordered map
  	std::unordered_map<int, int> ht;
  	if(operation != "remove_duplicates")
  	{
  		int x;
	  	while(istr >> x)
	  	{
	  		ht[x]++;
	  		input_count++;
	  	}
  	}
  	

  	//operations
  	if(operation == "sort")
  		std::cout << "it is not feasible/sensible to use operation with this data structure" << std::endl;
  	else if(operation == "remove_duplicates")
  	{
  		int x;
	  	while(istr >> x)
	  	{
	  		input_count++;
	  		if(ht[x] == 0)
	  		{
	  			ostr << x << std::endl;
	  			output_count++;
	  		}
	  		ht[x]++;
	  	}
  	}
  	else if(operation == "mode")
  		hash_mode(ht, ostr, output_count);
  	else if(operation == "closest_pair")
  		hash_closest_pair(ht, ostr, output_count);
  	else if(operation == "first_sorted")
  		std::cout << "it is not feasible/sensible to use operation with this data structure" << std::endl;
  	//no "longest_susbtring" for integers
  	else{
  		std::cerr << "Error: Unknown operation: " << operation << std::endl; 
  		usage();
  		exit(0);
  	}
  }

}
