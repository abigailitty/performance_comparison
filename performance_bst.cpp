#include <cassert>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <utility>


// defined in performance.cpp
void usage();

template <class T>
void map_sort(std::map<T, int> &mp, std::ostream &ostr, int &output_count) {
  output_count = mp.size();
  for (typename std::map<T, int>::iterator itr = mp.begin(); itr != mp.end(); itr++)
  	for(int i = 0; i < itr->second; i++)
    	ostr << itr->first << "\n";
}

//only for ints
void map_closest_pair(std::map<int,int> &mp, std::ostream &ostr, int &output_count){
  assert (mp.size() >= 2);
  
  std::map<int, int>::iterator itr1 = mp.begin();
  std::map<int, int>::iterator itr2 = mp.begin();
  itr2++;

  int first = itr1->first;
  int second = itr2->first;
  int best = abs(first-second);

  for(; itr2 != mp.end(); itr1++, itr2++)
  {
  	if(itr1->first != itr2->first && abs(itr2->first - itr1->first) < best)
  	{
  		first = itr1->first;
  		second = itr2->first;
  	}
  }

  // print the two elements
  output_count = 2;
  ostr << first << "\n";
  ostr << second << "\n";
}

template <class T>
void map_first_sorted(std::map<T, int> &mp, std::ostream &ostr, int &output_count, int optional_arg){
  assert (optional_arg >= 1);
  assert ((int)mp.size() >= optional_arg);
  
  output_count = optional_arg;

  typename std::map<T, int>::iterator itr = mp.begin();
  for (int i = 0; i < output_count; itr++)
  	for(int j = 0; j < itr->second; i++, j++)
  	{
  		if(i < output_count)
   			ostr << itr->first << "\n";
   		else
   			break;
  	}	
}

// note: longest_substring is only available for string data (not integer data)
void map_longest_substring(std::map<std::string, int> &mp, std::ostream &ostr, int &output_count) {
  assert(mp.size() >= 2);
  std::string longest = "";
  for(typename std::map<std::string, int>::iterator itr = mp.begin(); itr != mp.end(); itr++) //word
    for(int j = 0; j < int((itr->first).size()); j++) //all characters in word
      for(typename std::map<std::string, int>::iterator itr2 = std::next(itr, 1); itr2 != mp.end(); itr2++) //comparison word (all words after current word)
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

void bst_test(const std::string &operation, const std::string &type,
              std::istream &istr, std::ostream &ostr,
              int &input_count, int &output_count, int optional_arg) {

  // HINT: For the string element type, declare your binary search tree (BST) like this:
  // std::set<std::string> st;
  // OR 
  // std::map<std::string,int> mp;

 if(type == "string")
 {
 	std::map<std::string, int> mp;
 	if(operation != "remove_duplicates" && operation != "mode")
 	{
 		//build map

	 	std::string str;
	 	while(istr >> str)
	 	{
	 		mp[str]++;
	 		input_count++;
	 	}
 	}
 	

 	//operations
 	if(operation == "sort")
 		map_sort(mp, ostr, output_count);
 	else if(operation == "remove_duplicates")
 	{
 		//build map carefully
	 	std::string str;
	 	while(istr >> str)
	 	{
	 		input_count++;
	 		if(mp[str] == 0)
	 		{
	 			ostr << str << std::endl;
	 			output_count++;
	 		}
	 		mp[str]++;
	 	}
 	}
 	else if(operation == "mode")
 	{
 		std::string mode = "";
 		std::string str;
 		int largest_mode = 0;
 		while(istr >> str)
	 	{
	 		input_count++;
	 		mp[str]++;
	 		if(mp[str] > largest_mode)
	 		{
	 			largest_mode = mp[str];
	 			mode = str;
	 		}
	 	}

 		output_count = 1;
 		ostr << mode << std::endl;
 	}
 	//no "closest_pair" for strings
 	else if(operation == "first_sorted")
 		map_first_sorted(mp, ostr, output_count, optional_arg);
 	else if(operation == "longest_substring")
 		map_longest_substring(mp, ostr, output_count);
 	else{
  		std::cerr << "Error: Unknown operation: " << operation << std::endl; 
  		usage();
  		exit(0);
  	}
 
 }
 else
 {
 	//build set
 	std::map<int, int> mp;
 	if(operation != "remove_duplicates" && operation != "mode")
 	{
 		int x;
	 	while(istr >> x)
	 	{
	 		mp[x]++;
	 		input_count++;
	 	}

 	}
 	
 	//operations
 	if(operation == "sort")
 		map_sort(mp, ostr, output_count);
 	else if(operation == "remove_duplicates")
 	{
 		int x;
 		while(istr >> x)
	 	{
	 		input_count++;
	 		if(mp[x] == 0)
	 		{
	 			ostr << x << std::endl;
	 			output_count++;
	 		}
	 		mp[x]++;
	 	}
 	}
 	else if(operation == "mode")
 	{
 		int x;
 		int largest_mode = 0;
 		while(istr >> x)
	 	{
	 		input_count++;
	 		mp[x]++;
	 		if(mp[x] > largest_mode)
	 			largest_mode = x;
	 	}

 		output_count = 1;
 		ostr << largest_mode << std::endl;
 	}
 	else if(operation == "closest_pair")
 		map_closest_pair(mp, ostr, output_count);
 	else if(operation == "first_sorted")
 		map_first_sorted(mp, ostr, output_count, optional_arg);
 	//no "longest_substring" for integers
 	else{
  		std::cerr << "Error: Unknown operation: " << operation << std::endl; 
  		usage();
  		exit(0);
  	}
  }

}
