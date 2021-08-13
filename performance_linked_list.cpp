#include <cassert>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <string>
#include <list>
#include <cmath>
#include <iterator>


// defined in performance.cpp
void usage();

template <class T>
void list_sort(std::list<T> &lst, std::ostream &ostr, int &output_count) {
  // use the list sort algorithm
  lst.sort();
  output_count = lst.size();
  for (typename std::list<T>::iterator itr = lst.begin(); itr != lst.end(); itr++)
    ostr << *itr << "\n";
}

template <class T>
void list_remove_duplicates(std::list<T>& lst, std::ostream &ostr, int &output_count){
  // don't reorder the elements, just do all pairwise comparisons
  output_count = 0;
  for (typename std::list<T>::iterator itr = lst.begin(); itr != lst.end(); itr++) {
    bool dup = false;
    for (typename std::list<T>::iterator itr2 = lst.begin(); itr2 != itr; itr2++) {
      if (*itr == *itr2) {
        dup = true;
        break;
      }
    }
    // if it has not already been added to the output list
    if (!dup) {
      ostr << *itr << "\n";
      output_count++;
    }
  }
}

template <class T>
void list_mode(std::list<T>& lst, std::ostream &ostr, int &output_count){
  // use the list sort algorithm
  lst.sort();
  int current_count = 1;
  T mode;
  int mode_count = 0;
  // keep track of two iterators into the structure
  typename std::list<T>::iterator current = lst.begin();
  ++current;
  typename std::list<T>::iterator previous = lst.begin();
  for (; current != lst.end(); ++current, ++previous) {
    if (*current == *previous) {
      // if they are the same element increment the count
      current_count++;
    } else if (current_count >= mode_count) {
      // found a new mode!
      mode = *previous;
      mode_count = current_count;
      current_count = 1;
    } else {
      current_count = 1;
    }
  }
  if (current_count >= mode_count) {
    // last entry is a new mode!
    mode = *previous;
    mode_count = current_count;
  }
  // save the mode to the output list
  output_count = 1;
  ostr << mode << "\n";
}

// note: closest_pair is only available for integer data (not string data)
void list_closest_pair(std::list<int> &lst, std::ostream &ostr, int &output_count) {
  assert (lst.size() >= 2);
  // use the list sort algorithm
  lst.sort();
  output_count = 2;
  
  std::list<int>::iterator itr1 = lst.begin();
  std::list<int>::iterator itr2 = lst.begin();
  itr2++;

  int first = *itr1;
  int second = *itr2;
  int best = abs(first-second);

  for(; itr2 != lst.end(); itr1++, itr2++)
  {
  	if(*itr1 != *itr2 && abs(*itr2-*itr1) < best)
  	{
  		first = *itr1;
  		second = *itr2;
  	}
  }

  // print the two elements
  output_count = 2;
  ostr << first << "\n";
  ostr << second << "\n";
}

template <class T>
void list_first_sorted(std::list<T>& lst, std::ostream &ostr, int &output_count, int optional_arg){
  assert (optional_arg >= 1);
  assert ((int)lst.size() >= optional_arg);
  // use the list sort algorithm
  lst.sort();
  output_count = optional_arg;

  typename std::list<T>::iterator itr = lst.begin();
  for (int i = 0; i < output_count; i++, itr++)
    ostr << *itr << "\n";
}

// note: longest_substring is only available for string data (not integer data)
void list_longest_substring(std::list<std::string> &lst, std::ostream &ostr, int &output_count) {
  assert(lst.size() >= 2);
  std::string longest = "";
  for(typename std::list<std::string>::iterator itr = lst.begin(); itr != lst.end(); itr++) //word
    for(int j = 0; j < int((*itr).size()); j++) //all characters in word
      for(typename std::list<std::string>::iterator itr2 = std::next(itr, 1); itr2 != lst.end(); itr2++) //comparison word (all words after current word)
        for(int l = 0; l < int((*itr2).size()); l++) //all character in each comparison word
        {
          if(*itr != *itr2 && (*itr)[j] == (*itr2)[l])
          {
            std::string temp = "";
            int first_index = j;
            int second_index = l;

            while(first_index < int((*itr).size()) && second_index < int((*itr2).size()) &&
                  (*itr)[first_index] == (*itr2)[second_index])
            {
              temp += (*itr)[first_index];
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

void list_test(const std::string &operation, const std::string &type,
                 std::istream &istr, std::ostream &ostr,
                 int &input_count, int &output_count, int optional_arg) {

  // HINT: For the string element type, declare your list like this:
  // std::list<std::string> lst;

  if(type == "string")
  {
  	//build list
  	std::list<std::string> lst;
  	std::string s;
    input_count = 0;
    while (istr >> s) {
      lst.push_back(s);
      input_count++;
    }

    //operations
    if(operation == "sort")
    	list_sort(lst,ostr,output_count);
    else if(operation == "remove_duplicates")
  		list_remove_duplicates(lst, ostr, output_count);
  	else if(operation == "mode")
  		list_mode(lst, ostr, output_count);
  	//no "closest_pair" for strings
  	else if(operation == "first_sorted")
  		list_first_sorted(lst, ostr, output_count, optional_arg);
  	else if(operation == "longest_substring")
  		list_longest_substring(lst, ostr, output_count);
  	else{
  		std::cerr << "Error: Unknown operation: " << operation << std::endl; 
  		usage();
  		exit(0);
  	}

  }
  else
  {
  	//build list
  	std::list<int> lst;
  	int x;
  	input_count = 0;
  	while(istr >> x){
  		lst.push_back(x);
  		input_count++;
  	}

  	//operations
  	if(operation == "sort")
  		list_sort(lst, ostr, output_count);
  	else if(operation == "remove_duplicates")
  		list_remove_duplicates(lst, ostr, output_count);
  	else if(operation == "mode")
  		list_mode(lst, ostr, output_count);
  	else if(operation == "closest_pair")
  		list_closest_pair(lst, ostr, output_count);
  	else if(operation == "first_sorted")
  		list_first_sorted(lst, ostr, output_count, optional_arg);
  	// no "longest_substring" for integers
  	else{
  		std::cerr << "Error: Unknown operation: " << operation << std::endl; 
  		usage();
  		exit(0);
  	}
  }

}
