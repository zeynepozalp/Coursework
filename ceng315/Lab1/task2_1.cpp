#include <iostream>
#include <vector>
#include <algorithm>
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

void randomDigitArray(std::vector<int>& array, int size) {
  array.resize(size);
  srandom(time(0));
  for (int i = 0; i < size; i++) {
    array[i] = random() % 10;
  }
}


int testTask2(){

  std::vector<int> nums = {1, 1, 2, 3, 1, 0, 9, 8, 5, 7, 5};
  printVector(nums);
  sort(nums);
  printVector(nums);
  if (! std::is_sorted(nums.begin(),nums.end()))
    return 0;

  randomDigitArray(nums, 20);
  printVector(nums);
  sort(nums);
  printVector(nums);
  if (!std::is_sorted(nums.begin(),nums.end()))
    return 0;

  return 1;
}


int main(){

  if (testTask2()) {
    // std::cout << "PASSED TASK 2" << std::endl << std::endl;
    return 0;
  }
  else {
    // std::cout << "FAILED TASK 2" << std::endl << std::endl;
    return 1;
  }
}
