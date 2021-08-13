#include <cassert>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <cmath>


// defined in performance.cpp
void usage();

template <class T>
void queue_sort(std::priority_queue< T, std::vector<T>, std::greater<T> > &pq, std::ostream &ostr, int &output_count) {
  output_count = pq.size();
  while(!pq.empty()) 
  {
    ostr << pq.top() << std::endl;
    pq.pop();
  }
}

template <class T>
void queue_remove_duplicates(std::priority_queue< T, std::vector<T>, std::greater<T> > & pq, std::ostream &ostr, int &output_count){
  T prev_top = pq.top();
  ostr << pq.top() << std::endl;
  output_count++;
  pq.pop();

  while(!pq.empty())
  {
    if(pq.top() != prev_top)
    {
      ostr <<  pq.top() << std::endl;
      prev_top = pq.top();
      output_count++;
    }
    pq.pop();
  }
}

template <class T>
void queue_mode(std::priority_queue<T, std::vector<T>, std::greater<T> >& pq, std::ostream &ostr, int &output_count){
  int top_mode = 1;
  T highest = pq.top();
  int mode = 1;
  T temp = pq.top();
  pq.pop();

  while(!pq.empty())
  {
    if(pq.top() != temp)
    {
      if(mode > top_mode)
      {
        highest = temp;
        top_mode = mode;
      }
      mode = 1;
      temp = pq.top();
    }
    else
      mode++;

    pq.pop();
  }

  output_count = 1;
  ostr << highest << std::endl;
}

//only for ints
void queue_closest_pair(std::priority_queue<int, std::vector<int>, std::greater<int> >& pq, std::ostream &ostr, int &output_count){
  int first = pq.top();
  pq.pop();
  int second = pq.top();
  int compare_first = second;
  pq.pop();
  int best = abs(first - second);

  while(!pq.empty())
  {
    int compare_second = pq.top();
    pq.pop();

    if(compare_second != compare_first && abs(compare_second-compare_first) < best)
    {
      best = abs(compare_second-compare_first);
      first = compare_first;
      second = compare_second;
      compare_first = second;
    }
    compare_first = compare_second;
  }

  output_count = 2;
  ostr << first << "\n";
  ostr << second << "\n";
}

template <class T>
void queue_first_sorted(std::priority_queue<T, std::vector<T>, std::greater<T> >& pq, std::ostream &ostr, int &output_count, int optional_arg){
  assert (optional_arg >= 1);
  assert ((int)pq.size() >= optional_arg);
  
  output_count = optional_arg;

  int count = 0;
  while(count != optional_arg)
  {
    ostr << pq.top() << std::endl;
    pq.pop();
    count++;
  }
}

void priority_queue_test(const std::string &operation, const std::string &type,
                         std::istream &istr, std::ostream &ostr,
                         int &input_count, int &output_count, int optional_arg) {

  // HINT: For the string element type, declare your priority_queue like this:

  // std::priority_queue<std::string,std::vector<std::string> > pq;
  // (this will make a "max" priority queue, with big values at the top)

  // OR
  
  // std::priority_queue<std::string,std::vector<std::string>, std::greater<std::string> > pq;
  // (this will make a "min" priority queue, with big values at the bottom)

  if(type == "string")
  {
    //build priority queue
    std::priority_queue< std::string, std::vector<std::string>, std::greater<std::string> > pq;
    std::string str;
    while(istr >> str)
    {
      pq.push(str);
      input_count++;
    }

    //operations
    if(operation == "sort")
      queue_sort(pq, ostr, output_count);
    else if(operation == "remove_duplicates")
      queue_remove_duplicates(pq, ostr, output_count);
    else if(operation == "mode")
      queue_mode(pq, ostr, output_count);
    //no "closest_pair" for string
    else if(operation == "first_sorted")
      queue_first_sorted(pq, ostr, output_count, optional_arg);
    else if(operation == "longest_substring")
      std::cout << "it is not feasible/sensible to use operation with this data structure" << std::endl;
    else{
      std::cerr << "Error: Unknown operation: " << operation << std::endl; 
      usage();
      exit(0);
    }

  }
  else
  {
    std::priority_queue<int, std::vector<int>, std::greater<int> > pq;
    int x;
    while(istr >> x)
    {
      pq.push(x);
      input_count++;
    }

    //operations
    if(operation == "sort")
      queue_sort(pq, ostr, output_count);
    else if(operation == "remove_duplicates")
      queue_remove_duplicates(pq, ostr, output_count);
    else if(operation == "mode")
      queue_mode(pq, ostr, output_count);
    else if(operation == "closest_pair")
      queue_closest_pair(pq, ostr, output_count);
    else if(operation == "first_sorted")
      queue_first_sorted(pq, ostr, output_count, optional_arg);
    //no "longest_substring" for integers
    else{
      std::cerr << "Error: Unknown operation: " << operation << std::endl; 
      usage();
      exit(0);
    }

  }

}
