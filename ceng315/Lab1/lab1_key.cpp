#include "lab1.h"

// function declarations
// iterative search functions
int searchAllImplementedIter(std::vector<int>& nums, int num);
int findMaxElementIter(std::vector<int>& nums, int begin, int end);
int binarySearchIterInc(std::vector<int>& nums, int num, int begin, int end);
int binarySearchIterDec(std::vector<int>& nums, int num, int begin, int end);
int linearSearch(std::vector<int>& nums, int num);
// sort functions
void sortFast(std::vector<int>& nums);
void sortSlow(std::vector<int>& nums);
// odd section functions
int oddFast(std::vector<int>& nums);
int oddSlow(std::vector<int>& nums);

/**
 * Call different implementations here 
 */
int search(std::vector<int>& nums, int num) {

  return searchAllImplementedIter(nums, num);
  // return linearSearch(nums, num);
}

void sort(std::vector<int>& nums) {
  // sortSlow(nums);
  sortFast(nums);
}

int odd(std::vector<int>& nums) {
  // return oddSlow(nums);
  return oddFast(nums);
}

/**
 * First find the maximum element then use two binary searches in two parts
 * All three operations are in O(lgn)
 */
int searchAllImplementedIter(std::vector<int>& nums, int num){

  int begin = 0;
  int end = nums.size() - 1;
  int maxIndex = 0;
  int index = -1;

  if (begin <= end) {
    // maximum element
    maxIndex = findMaxElementIter(nums, begin, end);
    //
    if ((index = binarySearchIterInc(nums, num, begin, maxIndex)) != -1)
      return index;
    // 
    else if ((index = binarySearchIterDec(nums, num, maxIndex + 1, end)) != -1)
      return index;
  }
  
  // not found or nums size is 0
  return -1;
}

/**
 * Binary Search to find max element, non recursive
 * since integers are unique, compare to prev and next elements
 * to find whether you are in the inc or dec part
 * check for less then 3 elements
 */
int findMaxElementIter(std::vector<int>& nums, int begin, int end) {

  int middle;

  while (begin <= end) {
    // corner cases with size 1 or 2
    if (begin == end)
      return begin;
    else if (end - begin == 1) {
      if (nums[end] > nums[begin])
        return end;
      else
        return begin;
    }
    // at least 3 numbers
    middle = begin + (end - begin) / 2;
    // max element
    if (nums[middle] > nums[middle-1] && nums[middle] > nums[middle+1])
      return middle;
    // max is to the right
    else if (nums[middle] > nums[middle-1])
      begin = middle + 1;
    // max is to the left
    else
      end = middle - 1;
  }

  return -1;
}

/**
 * Binary Search in the increasing part 
 */
int binarySearchIterInc(std::vector<int>& nums, int num, int begin, int end) {
  
  int middle;

  while (begin <= end) {

    middle = begin + (end - begin) / 2;
    // correct element
    if (nums[middle] == num)
      return middle;
    // num is to the right
    else if (nums[middle] < num)
      begin = middle + 1;
    // num is to the left
    else
      end = middle - 1;
  }

  return -1;
}

/**
 * Binary Search in the decreasing part
 * only difference is the direction of comparison in (nums[middle] vs num)
 */
int binarySearchIterDec(std::vector<int>& nums, int num, int begin, int end) {
  
  int middle;

  while (begin <= end) {

    middle = begin + (end - begin) / 2;
    // correct element
    if (nums[middle] == num)
      return middle;
    // num is to the right
    else if (nums[middle] > num)
      begin = middle + 1;
    // num is to the left
    else
      end = middle - 1;
  }

  return -1;
}

int linearSearch(std::vector<int>& nums, int num) {

  auto it = std::find(nums.begin(), nums.end(), num);
  if (it != std::end(nums))
    return std::distance(nums.begin(), it);
  else
    return -1;
}


/**
 * A bucket sort implemenation
 * numbers are in range [0..9]
 */
void sortFast(std::vector<int>& nums) {
  
  int n = 0, i = 0, j = 0, size = nums.size();
  int counts[10] = {0};
  
  // find the count of each number
  for (auto const& num: nums)
    counts[num] += 1;

  // update the values in the original array
  while (i < size){
    if (j == counts[n]){
      j = 0;
      n++;
    }
    else{
      nums[i] = n;
      i++;
      j++;
    }
  }

  // if the array is empty this will do nothing
}

/**
 * A bucket sort implemenation
 * numbers are in range [0..9]
 */
void sortSlow(std::vector<int>& nums) {
  
  std::sort(nums.begin(), nums.end());

  // if the array is empty this will do nothing
}

/**
 * find total sum 
 * if its odd that's the answer
 * otherwise its even, substract the smallest odd sequence from one end
 * other alternatives are not possible since all numbers are positive
 */
int oddFast(std::vector<int>& nums) {

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


int oddSlow(std::vector<int>& nums) {
  // n^3
  int maxOddSum = 0;
  int size = nums.size();
  for (int i=0; i < size; i++) {
    for (int j=i; j <= size; j++) {
      int sum = std::accumulate(nums.begin()+i, nums.begin()+j, 0);
      if (sum % 2 == 1 && sum > maxOddSum)
        maxOddSum = sum;
    }
  }
  return maxOddSum;
}
