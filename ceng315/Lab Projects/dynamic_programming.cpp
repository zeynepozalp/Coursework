#include <iostream>
#include <limits.h>
using namespace std;
 /*NOTE TO SELF: Add timing!*/

/*Find the binomial coefficient C(n,k)*/

/*Simple Implementation*/
int binomialK(int n, int k){
  if(k==0 || n==k){
    return 1;
  }
  else{
    int result = 1;
    for(int i=0; i<k; i++){
      result *= (n-i);
      result /= i+1;
    }
    return result;
  }
}

/*Implementation using recursion*/
int binomialRec(int n, int k){
  if(k==0 || n==k){
    return 1;
  }
  else{
    return binomialRec(n-1,k-1) + binomialRec(n-1,k);
  }
}

/*Implementation using dynamic programming (bottom-up)*/
int binomialDP(int n, int k){
  int arr[n][k];

  for(int i=0; i<n; i++){
    arr[i][0]=1;
  }

  for(int i=0; i<k; i++){
    arr[0][i]=1;
  }

  for(int i=1; i<=n; i++){
    for(int j=1; j<=min(i,k); j++){
      if(j==0 || j==i){
        arr[i][j] = 1;
      }
      else{
        arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
      }
    }
  }
  return arr[n][k];
}

void testBinomial(){
  int n = 5; int k = 2;

  cout << "Testing binomial O(k): ";
  cout << "n is " << n << ", k is " << k << ". Answer is " << binomialK(n,k) << endl;

  cout << "Testing binomial recursion: ";
  cout << "n is " << n << ", k is " << k << ". Answer is " << binomialRec(n,k) << endl;

  cout << "Testing binomial dynamic: ";
  cout << "n is " << n << ", k is " << k << ". Answer is " << binomialDP(n,k) << endl;
}

/*Solution to the longest increasing subsequence problem using dynamic programming*/

/*Utility function*/
int findMAx(int arr[], int n){
  int index = 0;
  for(int i=0; i<n-1; i++){
    if(arr[i+1]>arr[i]) index=i+1;
  }
  return index;
}

int lisDP(int arr[], int n){
  int length[n];
  int sub[n];

  for(int i=0; i<n; i++){
    length[i]=1;
  }

  for(int i=1; i<n; i++){
    for(int j=0; j<i; j++){
      if(arr[j]<arr[i]){
        if(length[j]+1>=length[i]){
          length[i] = length[j]+1;
          sub[i]=j;
        }
      }
    }
  }

  int index = findMAx(length, n);
  int r=0;
  for(int i=0; i<n; i++){
    cout << arr[index] << " "; /*using vector is a good idea to print in ascending order*/
    index = sub[index];
    if(!index){
      cout << arr[index] << " "; /*This does not work when the first element is not included in LIS*/
      r=i+2;
      break;
    }
  }
  return r;
}

void testLis(){
  int arr1[] = {0,4,12,2,10,6,9,13,3,11,7,15};
  int n1 = 12;

  cout << "Testing LISDP #1: n is " << n1 << endl;
  cout << "LIS id (in reverse order): ";
  int l1 = lisDP(arr1, n1); cout << endl;
  cout << "Length of LIS is " << l1 << endl;

  int arr2[] = {10, 22, 9, 33, 21, 50, 41, 60};
  int n2 = 8;

  cout << "Testing LISDP #2: n is " << n2 << endl;
  cout << "LIS id (in reverse order): ";
  int l2 = lisDP(arr2, n2); cout << endl;
  cout << "Length of LIS is " << l2 << endl;

  /*This test gives wrong solution!*/
  int arr3[] = {50, 3, 10, 7, 40, 80};
  int n3 = 6;

  cout << "Testing LISDP #3: n is " << n3 << endl;
  cout << "LIS id (in reverse order): ";
  int l3 = lisDP(arr3, n3); cout << endl;
  cout << "Length of LIS is " << l3 << endl;
}

/*Cutting a Rod*/

/*Recursive solution*/
int rodRec(int price[], int n){
  if(n<=0) return 0;
  int maxx = -1;

  for(int i=0; i<n;i++){
    maxx = max(maxx, price[i] + rodRec(price, n-i-1));
  }
  return maxx;
}

/*Dynamic Programming*/
int rodDP(int price[], int n){
  int arr[n+1];
  arr[0]=0;

  for(int i=1; i<=n; i++){
    int maxx = INT_MIN;
    for(int j=0; j<i; j++){
      maxx = max(maxx, price[j]+arr[i-j-1]);
    }
    arr[i] = maxx;
  }

  return arr[n];
}

void testRod(){
  int arr1[] = {1, 5, 8, 9, 10, 17, 17, 20};
  int n1 = 8;

  cout << "Testing rod cutting recursion #1: ";
  cout << "Answer is " << rodRec(arr1, n1) << endl;
  cout << "Testing rod cutting dynamic #1: ";
  cout << "Answer is " << rodDP(arr1, n1) << endl;

  int arr2[] = {4, 5, 8, 9, 10, 17, 17, 20};
  int n2 = 8;

  cout << "Testing rod cutting recursion #2: ";
  cout << "Answer is " << rodRec(arr2, n2) << endl;
  cout << "Testing rod cutting dynamic #2: ";
  cout << "Answer is " << rodDP(arr2, n2) << endl;
}

int main(){
  cout << "Dynamic Programming Lab Exam Practice" << endl;
  cout<<"------------------------------"<<endl;
  testBinomial();
  cout<<"------------------------------"<<endl;
  testLis();
  cout<<"------------------------------"<<endl;
  testRod();
  return 0;
}
