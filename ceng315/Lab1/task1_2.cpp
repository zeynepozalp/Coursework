#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <cassert>
#include "lab1.h"


void printVector(std::vector<int>& nums){

    std::cout << "size: " << nums.size() << std::endl;
    for (unsigned i = 0; i < nums.size(); ++i){
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
}

void randomUniqueNumberArray(std::vector<int>& nums,
                             int size, int max, int min=0){

  nums.resize(size);
  srandom(time(0));
  // Knuth
  int j = 0;
  for (int i = min; i < max && j < size; ++i) {
    int range = max - i;
    int remain = size - j;
    if (random() % range < remain)
      nums[j++] = i;
  }
  assert(j == size);
  // sorted before this
  std::random_device rd;
  std::mt19937 g(rd());
  std::shuffle(nums.begin(), nums.end(), g);
}

void bitonicArray(std::vector<int>& nums,
                  int size, int max, int min=0, int split=-1){

  randomUniqueNumberArray(nums, size, max, min);
  if (size > 0) {
    int maxIndex = split < 0 ? random() % nums.size() : split;
    std::sort(nums.begin(), nums.begin() + maxIndex);
    std::sort(nums.begin() + maxIndex, nums.end(), std::greater<int>());
  }
}


int testTask1(int size, int max, int min=0){

  std::vector<int> nums;

  int index;
  int index_ans;
  int iterations = 10;

  double total_time = 0;
  clock_t begin;
  clock_t end;
  double duration;

  for (int i = 0; i < iterations; ++i){

    int num = random() % (int)((max - min) * 1.1) + min * 1.1;
    bitonicArray(nums, size, max, min);
    // force some numbers to be in the array
    if (i % 3 == 0)
        num = nums[i % size];
    //
    auto it = std::find(nums.begin(), nums.end(), num);
    if (it != std::end(nums))
      index_ans =  std::distance(nums.begin(), it);
    else
      index_ans =  -1;
    //
    if ((begin = clock ()) == -1) 
      std::cerr << "clock err" << std::endl;
    //
    index = search(nums, num);
    //
    if ((end = clock ()) == -1) 
      std::cerr << "clock err" << std::endl;
    //
    duration = ((double)end-begin) / CLOCKS_PER_SEC * 1000000;
    total_time += duration;

    if (index != index_ans){
      std::cout << "Expected " << index_ans << " given " << index << std::endl;
      // std::cout << num << std::endl;
      return -1;
    }
  }

  return (int) (total_time / iterations);
}

int main(){

  int result;

  int nums_sizes[4]     = { 10000,   100000,   100000, 1000000};
  int max_value[4]      = { 90000,  1000000,  1000000, 2000000};
  int min_value[4]      = {     0, -1000000, -1000000,       0};
  int expected_times[4] = {    25,       25,       25,      25};
  
  for (int i = 0; i < 4; ++i)
  {
    result = testTask1(nums_sizes[i], max_value[i], min_value[i]);
    if (result == -1){
      std::cout << "Wrong answer" << std::endl;
      return 1;
    }
    std::cout << result << " microsecs for " << nums_sizes[i] << std::endl;
    if (result > expected_times[i]){
      std::cout << "Slower than expected with " << result << " vs " << expected_times[i] << " microsecs" << std::endl;
      return 1;
    }
    std::cout << std::endl;    
  }

  return 0;
}
