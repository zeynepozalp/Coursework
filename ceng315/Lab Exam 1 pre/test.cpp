#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cassert>
#include "lab1.h"


void randomArray(std::vector<int>& array, int size, int max, int min=0){

  array.resize(size);
  srandom(time(0));
  for (int i = 0; i < size; ++i){
    array[i] = random() % (max - min) + min;
  }
}

void randomArrayUniqueSorted(std::vector<int>& array, int size, int max, int min=0){

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
}


void rotateArray(std::vector<int>& array, int rotates=-1){

  int rotate = rotates < 0 ? random() % array.size() : rotates;
  std::rotate(array.begin(), array.begin()+rotate, array.end());
}


void randomGrid(std::vector<std::vector<int>>& grid, int rows, int cols, int max, int min=0){

  grid.resize(rows);
  srandom(time(0));
  for (int i = 0; i < rows; ++i){
    grid[i].resize(cols);
    for (int j = 0; j < cols; ++j){
      grid[i][j] = random() % (max - min) + min;
    }
  }
}


void printVector(std::vector<int>& array){

  std::cout << "size: " << array.size() << std::endl;
  for (auto item: array){
    std::cout << item << " ";
  }
  std::cout << std::endl;
}


void printGrid(std::vector<std::vector<int>>& grid){

  std::cout << "size: " << grid.size() << "x" << grid[0].size() << std::endl;
  for (auto row: grid){
    for (auto item: row){
      std::cout << item << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}


void measureTime(){

  clock_t begin;
  clock_t end;
  double duration;

  // maybe data genereation here

  if ((begin = clock ()) == -1) 
    std::cerr << "clock err" << std::endl; 

  // call your function here instead of the loop
  for (int i = 0; i < 1<<30; i++)
    ;
  //

  if ((end = clock ()) == -1) 
    std::cerr << "clock err" << std::endl;
  duration = ((double)end-begin) / CLOCKS_PER_SEC * 1000000;

  std::cerr << "Times: " << begin <<" "<< end << " " << end-begin << " "<< duration <<" microsecs " << std::endl;
}


void testTask1Ex(){

  std::vector<std::vector<int>> grid = {
    {3, 0, 8},
    {2, 4, 5},
    {9, 2, 3}
  };
  
  std::cout << skyline(grid) << std::endl;
}


void testTask1(int rows, int cols, int max, int min=0){

  std::vector<std::vector<int>> grid;
  randomGrid(grid, rows, cols, max, min);
  skyline(grid);
}


void testTask2Ex(){

  std::vector<int> array = {3, 4, 5, 6, 7, 8, 0, 1, 2};
  
  std::cout << search(array, 5) << std::endl;
  std::cout << search(array, 1) << std::endl;
  std::cout << search(array, 9) << std::endl;
}


void testTask2(int size, int max, int min=0){

  std::vector<int> array;
  int num = random() % (int)((max - min) * 1.1) + min * 1.1;
  randomArrayUniqueSorted(array, size, max, min);
  rotateArray(array);
  search(array, num);
}


int main(){


  std::vector<int> array1, array2;
  randomArray(array1, 10, 10, -10);
  printVector(array1);
  randomArrayUniqueSorted(array2, 10, 20);
  printVector(array2);
  rotateArray(array2, 3);
  printVector(array2);
  rotateArray(array2);
  printVector(array2);
  std::cout << std::endl;

  std::vector<std::vector<int>> grid;
  randomGrid(grid, 4, 6, 10);
  printGrid(grid);
  std::cout << std::endl;

  // TASK 1

  std::cout << "TASK 1" << std::endl;
  testTask1Ex();
  //
  testTask1(5, 5, 40);
  std::cout << std::endl;

  // TASK 2
  std::cout << "TASK 2" << std::endl;
  testTask2Ex();
  //
  testTask2(1000, 500000, -500000);
  std::cout << std::endl;

  return 0;
}
