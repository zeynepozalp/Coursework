#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <cassert>
#include "lab1.h"

int oddSolution(std::vector<int>& nums) {

  int sum = 0, sumLeft = 0, sumRight = 0;
  int size = nums.size();

  // int sum = std::accumulate(nums.begin(), nums.end(), 0);
  for (auto const& num: nums)
    sum += num;

  if (sum % 2 == 1)
    return sum;
  
  // from left
  for (int i = 0; i < size; i++){
    sumLeft += nums[i];
    // break at the first odd sum
    if (sumLeft % 2 == 1)
      break;
  }
  
  // from right
  for (int i = size - 1; i >= 0; i--){
    sumRight += nums[i];
    // break at the first odd sum
    if (sumRight % 2 == 1)
      break;
  }
  
  // this also covers no odd sum case and returns 0
  if (sumLeft < sumRight)
    return sum - sumLeft;
  else
    return sum - sumRight;
}


void printVector(std::vector<int>& array){

    std::cout << "size: " << array.size() << std::endl;
    for (unsigned i = 0; i < array.size(); ++i){
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void randomArray(std::vector<int>& array, int size) {
  array.resize(size);
  srandom(time(0));
  for (int i = 0; i < size; i++) {
    array[i] = random() % 1000;
  }
}


int testTask3(int size){

  std::vector<int> nums;
  int sum;
  int sum_ans;
  int iterations = 10;

  double total_time = 0;
  clock_t begin;
  clock_t end;
  double duration;

  for (int i = 0; i < iterations; ++i){

    /* it is better to modify this and give some selected numbers from the nums 
       instead of only random numbers
    */
    randomArray(nums, size);
    sum_ans = oddSolution(nums);
    //
    if ((begin = clock ()) == -1) 
      std::cerr << "clock err" << std::endl;
    //
    sum = odd(nums);
    //
    if ((end = clock ()) == -1) 
      std::cerr << "clock err" << std::endl;
    //
    duration = ((double)end-begin) / CLOCKS_PER_SEC * 1000000;
    total_time += duration;

    if (sum != sum_ans){
      std::cout << "Expected " << sum_ans << " given " << sum << std::endl;
      return -1;
    }
  }
  return (int) (total_time / iterations);
}

int main(){
  
  int result;

  int nums_sizes[4]     = { 1000,   10000,   100000, 1000000};
  int expected_times[4] = {  100,    1000,    10000,  100000};
  
  for (int i = 0; i < 4; ++i)
  {
    result = testTask3(nums_sizes[i]);
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
