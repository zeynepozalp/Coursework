#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <cassert>
#include "lab1.h"


void printVector(std::vector<int>& v){

    std::cout << "size: " << v.size() << std::endl;
    for (unsigned i = 0; i < v.size(); ++i){
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

void randomDigitArray(std::vector<int>& nums, int size) {
  nums.resize(size);
  srandom(time(0));
  for (int i = 0; i < size; i++) {
    nums[i] = random() % 10;
  }
}


int testTask2(int size){

  std::vector<int> nums;
  int iterations = 10;

  double total_time = 0;
  clock_t begin;
  clock_t end;
  double duration;

  for (int i = 0; i < iterations; ++i){

    /* it is better to modify this and give some selected numbers from the nums 
       instead of only random numbers
    */
    randomDigitArray(nums, size);
    //
    if ((begin = clock ()) == -1) 
      std::cerr << "clock err" << std::endl;
    //
    sort(nums);
    //
    if ((end = clock ()) == -1) 
      std::cerr << "clock err" << std::endl;
    //
    duration = ((double)end-begin) / CLOCKS_PER_SEC * 1000000;
    total_time += duration;

    if (!std::is_sorted(nums.begin(),nums.end())){
      std::cout << "Numbers are not sorted correctly" << std::endl;
      return -1;
    }
  }
  return (int) (total_time / iterations);
}

int main(){
  
  int result;

  int nums_sizes[4]     = { 1000,   10000,   100000, 1000000};
  int expected_times[4] = {  250,    5000,    50000,  500000};
  
  for (int i = 0; i < 4; ++i)
  {
    result = testTask2(nums_sizes[i]);
    if (result == -1){
      std::cout << "Wrong answer" << std::endl;
      return 1;
    }
    std::cout << result << " microsecs for " << nums_sizes[i] << std::endl;
    if (result > expected_times[i]){
      std::cout << "Slower than expected with " << result << " vs " 
        << expected_times[i] << " microsecs" << std::endl;
      return 1;
    }
    std::cout << std::endl;    
  }

  return 0;
}
