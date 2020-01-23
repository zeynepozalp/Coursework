#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <cassert>
#include "lab1.h"


void printVector(std::vector<int>& array){

    std::cout << "size: " << array.size() << std::endl;
    for (unsigned i = 0; i < array.size(); ++i){
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void randomUniqueNumberArray(std::vector<int>& array,
                             int size, int max, int min=0){

  array.resize(size);
  srandom(time(0));
  // Knuth
  int j = 0;
  for (int i = min; i < max && j < size; ++i) {
    int range = max - i;
    int remain = size - j;
    if (random() % range < remain)
      array[j++] = i;
  }
  assert(j == size);
  // sorted before this
  std::random_device rd;
  std::mt19937 g(rd());
  std::shuffle(array.begin(), array.end(), g);
}

void bitonicArray(std::vector<int>& array,
                  int size, int max, int min=0, int split=-1){

  randomUniqueNumberArray(array, size, max, min);
  if (size > 0) {
    int maxIndex = split < 0 ? random() % array.size() : split;
    std::sort(array.begin(), array.begin() + maxIndex);
    std::sort(array.begin() + maxIndex, array.end(), std::greater<int>());
  }
}


int testTask1(){

  std::vector<int> nums = {0, 1, 3, 4, 7, 8, 6, 5, 2};

  if (search(nums, 5) != 7){
    std::cout << "Wrong answer for {0, 1, 3, 4, 7, 8, 6, 5, 2}; 5" << std::endl;
    return 0;
  }

  if (search(nums, 3) != 2){
    std::cout << "Wrong answer for {0, 1, 3, 4, 7, 8, 6, 5, 2}; 3" << std::endl;
    return 0;
  }

  if (search(nums, 0) != 0){
    std::cout << "Wrong answer for {0, 1, 3, 4, 7, 8, 6, 5, 2}; 0" << std::endl;
    return 0;
  }

  if (search(nums, 2) != 8){
    std::cout << "Wrong answer for {0, 1, 3, 4, 7, 8, 6, 5, 2}; 2" << std::endl;
    return 0;
  }

  if (search(nums, 8) != 5){
    std::cout << "Wrong answer for {0, 1, 3, 4, 7, 8, 6, 5, 2}; 8" << std::endl;
    return 0;
  }

  if (search(nums, 9) != -1){
    std::cout << "Wrong answer for {0, 1, 3, 4, 7, 8, 6, 5, 2}; 9" << std::endl;
    return 0;
  }

  if (search(nums, -1) != -1){
    std::cout << "Wrong answer for {0, 1, 3, 4, 7, 8, 6, 5, 2}; -1" << std::endl;
    return 0;
  }

  bitonicArray(nums, 0, 100);
  if (search(nums, 0) != -1){
    std::cout << "Wrong answer for 5 in empty array" << std::endl;
    return 0;
  }

  if (search(nums, 3) != -1){
    std::cout << "Wrong answer for 5 in empty array" << std::endl;
    return 0;
  }

  bitonicArray(nums, 20, 100);
  printVector(nums);

  if (search(nums, nums[0]) != std::distance(nums.begin(), 
      std::find(nums.begin(), nums.end(), nums[0]))){
    std::cout << "Wrong answer for " << nums[0] << " in random array" << std::endl;
    return 0;
  }

  if (search(nums, nums[9]) != std::distance(nums.begin(), 
      std::find(nums.begin(), nums.end(), nums[9]))){
    std::cout << "Wrong answer for " << nums[9] << " in random array" << std::endl;
    return 0;
  }

  if (search(nums, nums[19]) != std::distance(nums.begin(), 
      std::find(nums.begin(), nums.end(), nums[19]))){
    std::cout << "Wrong answer for " << nums[19] << " in random array" << std::endl;
    return 0;
  }
  if (search(nums, -10) != -1){
    std::cout << "Wrong answer for -10 in random array" << std::endl;
    return 0;
  }

  if (search(nums, 120) != -1){
    std::cout << "Wrong answer for 120 in random array" << std::endl;
    return 0;
  }

  return 1;
}


int main(){

  if (testTask1()) {
    // std::cout << "PASSED TASK 1" << std::endl << std::endl;
    return 0;
  }
  else {
    // std::cout << "FAILED TASK 1" << std::endl << std::endl;
    return 1;
  }
}
