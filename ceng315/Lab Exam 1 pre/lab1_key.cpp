#include "lab1_key.h"


int skylineSlow315(std::vector<std::vector<int>>& grid) {

  int increase = 0;
  int numRows = grid.size();
  int numColumns = grid[0].size();

  for (int i = 0; i < numRows; ++i){
    for (int j = 0; j < numColumns; ++j) {
      int maxEastWest = 0, maxNorthSouth = 0;
      for (int r = 0; r < numRows; ++r) {
        if (grid[r][j] > maxNorthSouth)
          maxNorthSouth = grid[r][j];
      }
      for (int c = 0; c < numColumns; ++c) {
        if (grid[i][c] > maxEastWest)
          maxEastWest = grid[i][c];
      }
      if (maxEastWest > maxNorthSouth)
        increase += maxNorthSouth - grid[i][j];
      else
        increase += maxEastWest - grid[i][j];
    }
  }

  return increase;
}


int skylineSlow316(std::vector<std::vector<int>>& grid) {

  auto increase = 0;
  auto numRows = grid.size();
  auto numColumns = grid[0].size();

  for (size_t i = 0; i < numRows; ++i) {
    for (size_t j = 0; j < numColumns; ++j) {
      auto maxNorthSouthIt = std::max_element(grid.begin(), grid.end(), 
            [j] (decltype(grid[0]) p1, decltype(grid[0]) p2) { return p1[j] < p2[j]; });
      auto maxNorthSouth = (*maxNorthSouthIt)[j];
      auto maxEastWestIt = std::max_element(grid[i].begin(), grid[i].end());
      auto maxEastWest = *maxEastWestIt;
      increase += std::min(maxNorthSouth, maxEastWest) - grid[i][j];
    }
  }
  return increase;
}


int skylineFast315(std::vector<std::vector<int>>& grid){

  int increase = 0;
  int numRows = grid.size();
  int numColumns = grid[0].size();

  std::vector<int> eastWest(numRows, 0);
  std::vector<int> northSouth(numColumns, 0);

  for (int r = 0; r < numRows; ++r) {
    int maxEastWest = 0;
    for (int c = 0; c < numColumns; ++c) {
      if (grid[r][c] > maxEastWest)
        maxEastWest = grid[r][c];
    }
    eastWest[r] = maxEastWest;
  }
  for (int c = 0; c < numColumns; ++c) {
    int maxNorthSouth = 0;
    for (int r = 0; r < numRows; ++r) {
      if (grid[r][c] > maxNorthSouth)
        maxNorthSouth = grid[r][c];
    }
    northSouth[c] = maxNorthSouth;
  }

  for (int r = 0; r < numRows; ++r) {
    for (int c = 0; c < numColumns; ++c) {
      if (eastWest[r] > northSouth[c])
        increase += northSouth[c] - grid[r][c];
      else
        increase += eastWest[r] - grid[r][c];
    }
  }

  return increase;
}


int skylineFast316(std::vector<std::vector<int>>& grid){

  int increase = 0;
  int numRows = grid.size();
  int numColumns = grid[0].size();

  std::vector<int> eastWest(numRows, 0);
  std::vector<int> northSouth(numColumns, 0);

  for (int r = 0; r < numRows; ++r) {
    for (int c = 0; c < numColumns; ++c) {
      if (grid[r][c] > eastWest[r])
        eastWest[r] = grid[r][c];
      if (grid[r][c] > northSouth[c])
        northSouth[c] = grid[r][c];
    }
  }

  for (int r = 0; r < numRows; ++r) {
    for (int c = 0; c < numColumns; ++c) {
      if (eastWest[r] > northSouth[c])
        increase += northSouth[c] - grid[r][c];
      else
        increase += eastWest[r] - grid[r][c];
    }
  }

  return increase;
}


int skylineFast317(std::vector<std::vector<int>>& grid){

  auto increase = 0;
  auto numRows = grid.size();
  auto numColumns = grid[0].size();

  std::vector<int> eastWest(numRows, 0);
  std::vector<int> northSouth(numColumns, 0);

  for (size_t r = 0; r < numRows; ++r) {
    auto maxEastWestIt = std::max_element(grid[r].begin(), grid[r].end());
    eastWest[r] = *maxEastWestIt;
  }
  for (size_t c = 0; c < numColumns; ++c) {
    auto maxNorthSouthIt = std::max_element(grid.begin(), grid.end(), 
            [c] (decltype(grid[0]) p1, decltype(grid[0]) p2) { return p1[c] < p2[c]; });
    northSouth[c] = (*maxNorthSouthIt)[c];
  }

  for (size_t r = 0; r < numRows; ++r) {
    for (size_t c = 0; c < numColumns; ++c) {
      increase += std::min(northSouth[c], eastWest[r]) - grid[r][c];
    }
  }

  return increase;
}


int skylineSolution315(std::vector<std::vector<int>>& grid){
  return skylineFast316(grid);
}


/* ------- */


int searchSlow315(std::vector<int>& array, int num){

  unsigned int index = 0;

  while (index < array.size()){
    if (array[index] == num)
      return index;
    ++index;
  }

  return -1;
}


int searchSlow316(std::vector<int>& array, int num){

  auto len = array.size();
  for (size_t i = 0; i < len; ++i){
    if (array[i] == num)
      return i;
  }

  return -1;
}


int searchSlow317(std::vector<int>& array, int num){

  auto it = std::find(array.begin(), array.end(), num);
  if (it != array.end())
    return it - array.begin();
  else
    return -1;
}


int searchFast316(std::vector<int>& array, int num){
  
  int start = 0;
  int end = array.size() - 1;
  int middle = 0;

  while (start <= end){
    
    middle = (end - start) / 2 + start;
    // cout << start << " " << middle << " " << end << endl;
    if (array[middle] == num)
      return middle;
    else if (array[middle] < num)
      if (array[middle] < array[end])
        if (array[end] < num)
          end = middle - 1;
        else
          start = middle + 1;
      else
        start = middle + 1;
    else
      if (array[start] < array[middle])
        if (array[start] <= num)
          end = middle - 1;
        else
          start = middle + 1;
      else
        end = middle - 1;
      // cout <<  "\t" << start << " " << end << endl;
  }

  return -1;
}


int searchFast317(std::vector<int>& array, int num){
  
  int start = 0;
  int end = array.size() - 1;
  int middle = 0;

  while (start <= end){
    middle = (end - start) / 2 + start;
    if (array[middle] == num)
      return middle;
    else if (array[middle] < array[end])
      if (array[middle] < num)
        if (num <= array[end])
          start = middle + 1;
        else
          end = middle - 1;
      else
        end = middle - 1;
    else
      if (num < array[middle])
        if (array[start] <= num)
          end = middle - 1;
        else
          start = middle + 1;
      else
        start = middle + 1;
  }

  return -1;
}


int searchFast318(std::vector<int>& array, int num){
  
  int start = 0;
  int end = array.size() - 1;
  int middle = 0;

  while (start <= end){
    middle = (end - start) / 2 + start;
    if (array[middle] == num)
      return middle;
    else if (array[middle] < array[end])
      if (array[middle] < num && num <= array[end])
        start = middle + 1;
      else
        end = middle - 1;
    else
      if (num < array[middle] && array[start] <= num)
        end = middle - 1;
      else
        start = middle + 1;
  }

  return -1;
}


int searchSolution315(std::vector<int>& array, int num){
  return searchFast318(array, num);
}
