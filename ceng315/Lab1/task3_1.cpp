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


int testTask3(){

  std::vector<int> nums {};

  if (odd(nums) != 0){
    std::cout << "Wrong answer for empty list" << std::endl;
    return 0;
  }

  nums = {6, 4, 2, 4, 2};
  printVector(nums);
  if (odd(nums) != 0){
    std::cout << "Wrong answer for {6, 4, 2, 4, 2}" << std::endl;
    return 0;
  }

  nums = {1, 4, 2, 4, 2};
  printVector(nums);
  if (odd(nums) != 13){
    std::cout << "Wrong answer for {1, 4, 2, 4, 2}" << std::endl;
    return 0;
  }

  nums = {6, 4, 2, 1, 1, 2, 3, 1, 0, 9, 8, 5, 4, 2};
  printVector(nums);
  if (odd(nums) != 37){
    std::cout << "Wrong answer for {6, 4, 2, 1, 1, 2, 3, 1, 0, 9, 8, 5, 4, 2}" << std::endl;
    return 0;
  }


  return 1;
}



int main(){

  if (testTask3()) {
    // std::cout << "PASSED TASK 3" << std::endl << std::endl;
    return 0;
  }
  else {
    // std::cout << "FAILED TASK 3" << std::endl << std::endl;
    return 1;
  }
}
