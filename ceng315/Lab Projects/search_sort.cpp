#include <vector>
#include <iostream>

using namespace std;

/* Find the transition point in a sorted vector. Complexity: O(logn)*/

int transitionPoint(vector<int>& vec){
  unsigned first = 0;
  unsigned last = vec.size()-1;

  if(vec[first]==1){
    cout << "All ones. No transition point." << endl;
  }
  else if(vec[last]==0){
    cout << "All zeros. No transition point." << endl;
  }
  else{
    while (first<=last) {
      unsigned mid = (first+last)/2;

      if(vec[mid]==1 && vec[mid-1]==0) return mid;
      else if (vec[mid]==1)  last = mid-1;
      else first = mid+1;
    }
  }
  return -1;
}

void testTransition(){
  vector<int> vec1 = {0,0,0,0,0,1,1,1,1,1};
  vector<int> vec2 = {0,0,1,1,1,1,1};
  vector<int> vec3 = {0,0,0};
  vector<int> vec4 = {1,1,1};

  cout << "Test transitionPoint 1: " << transitionPoint(vec1) << endl;
  cout << "Test transitionPoint 2: " << transitionPoint(vec2) << endl;
  cout << "Test transitionPoint 3: " << transitionPoint(vec3) << endl;
  cout << "Test transitionPoint 4: " << transitionPoint(vec4) << endl;
}

/* Find the number of zeros in a sorted vector. Complexity : O(logn)*/

int noOfZeros(vector<int>& vec){
  unsigned first = 0;
  unsigned last = vec.size()-1;

  if(vec[first]==1){
    cout << "All ones. No zeros." << endl;
    return 0;
  }
  else if(vec[last]==0){
    cout << "All zeros." << endl;
    return vec.size();
  }
  else{
    while (first<=last) {
      unsigned mid = (first+last)/2;

      if(vec[mid]==1 && vec[mid-1]==0) return mid;
      else if (vec[mid]==1)  last = mid-1;
      else first = mid+1;
    }
  }
}

void testNoOfZeros(){
  vector<int> vec1 = {0,0,0,0,0,1,1,1,1,1};
  vector<int> vec2 = {0,0,1,1,1,1,1};
  vector<int> vec3 = {0,0,0};
  vector<int> vec4 = {1,1};

  cout << "Test noOfZeros 1: " << noOfZeros(vec1) << endl;
  cout << "Test noOfZeros 2: " << noOfZeros(vec2) << endl;
  cout << "Test noOfZeros 3: " << noOfZeros(vec3) << endl;
  cout << "Test noOfZeros 4: " << noOfZeros(vec4) << endl;
}

/* Merge Sort */

void merge(vector<int>& vec, int l ,int m, int r){
  int i, j, k;
  int n1 = m - l + 1;
  int n2 =  r - m;
  vector<int> left(n1), right(n2);

  for (i = 0; i < n1; i++) left[i] = vec[l + i];
  for (j = 0; j < n2; j++) right[j] = vec[m + 1+ j];

  i=0; j=0; k=l;
  while(i<n1 && j<n2){
    if(left[i]<right[j]){
      vec[k] = left[i]; i++;
    }
    else{
      vec[k] = right[j]; j++;
    }
    k++;
  }
  while(i < n1){
    vec[k] = left[i]; i++; k++;
  }
  while(j < n2){
    vec[k] = right[j]; j++; k++;
  }
}

void mergeSort(vector<int>& vec, int l, int r){
  if(l<r){
    unsigned mid = l+(r-l)/2;

    mergeSort(vec, l, mid);
    mergeSort(vec, mid+1, r);
    merge(vec, l, mid, r);
  }
}

/*Print Vector*/

void printVector(vector<int>& v){
  for(unsigned i=0; i<v.size(); i++){
    cout << v[i] << " ";
  }
  cout << endl;
}

/* Find the smallest kth element in an unsorted vector. No dublicates in the array. Complexity : O(nlogn)*/
/* Note: Try using heap and O(n) complexity!*/

int findKthSmallest(vector<int>& vec, int k){
  cout << "Before merge sort : ";
  printVector(vec);

  mergeSort(vec, 0, vec.size()-1);

  cout << "After merge sort : ";
  printVector(vec);

  return vec[k-1];
}

void testKthSmallest(){
  vector<int> vec1 = {1,8,7,3,9,57,23,45,65,2};
  vector<int> vec2 = {0,76,2,4,67,8,34,54,76};
  vector<int> vec3 = {56,4,3,2,89,5,34,12,445,787,7856};
  vector<int> vec4 = {45,687,8,343,5,79,3,2,4,68,9,65};

  cout << "Test findKthSmallest 1: 6th smallest is " << findKthSmallest(vec1, 1) << endl;
  cout << "Test findKthSmallest 2: 5th smallest is " << findKthSmallest(vec2, 5) << endl;
  cout << "Test findKthSmallest 3: 10th smallest is " << findKthSmallest(vec3, 10) << endl;
  cout << "Test findKthSmallest 4: 3rd smallest is " << findKthSmallest(vec4, 3) << endl;
}

int binarySearch(vector<int>& vec, int l, int r, int k){
  while(l<=r){
    int mid = l+(r-l)/2;

    if(vec[mid]==k) return mid;
    else if(vec[mid] > k) return binarySearch(vec, l, mid-1, k);
    else return binarySearch(vec, mid+1, r, k);
  }
  return -1;
}

void testBinarySearch(){
  vector<int> vec1 = {0,1,2,3,4,5,6,7,8};
  vector<int> vec2 = {3,4,5,6,7,8};
  vector<int> vec3 = {0,1,2};
  vector<int> vec4 = {5,6,7,8,9,10,11,12,13};

  cout << "Test binarySearch 1: 6 is at index " << binarySearch(vec1, 0, vec1.size()-1, 6) << endl;
  cout << "Test binarySearch 2: 6 is at index " << binarySearch(vec2, 0, vec2.size()-1, 6) << endl;
  cout << "Test binarySearch 3: 6 is at index " << binarySearch(vec3, 0, vec3.size()-1, 6) << endl;
  cout << "Test binarySearch 4: 6 is at index " << binarySearch(vec4, 0, vec4.size()-1, 6) << endl;

}

int main(){
    cout << "Searching/Sorting Alogorithms Lab Exam Practice" << endl;
    cout<<"------------------------------"<<endl;
    testTransition();
    cout<<"------------------------------"<<endl;
    testNoOfZeros();
    cout<<"------------------------------"<<endl;
    testKthSmallest();
    cout<<"------------------------------"<<endl;
    testBinarySearch();
}
