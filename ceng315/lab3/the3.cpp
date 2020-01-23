#include "the3.h"

using namespace std;

void DFSUtil(int n, int**& edgeList, int v, bool*& visited){
    visited[v] = true;
    int i;
    for (i=0; i<n; i++){
      if(edgeList[v][i]!=INT_MAX){
          if(!visited[i]){
              DFSUtil(n, edgeList, i, visited);
          }
      }
    }
}

int numberOfComponents(int n, int**& edgeList){
    bool* visited = new bool[n];
    int count = 0;
    for (int v = 0; v < n; v++){
        visited[v] = false;
    }
    for (int v = 0; v < n; v++) {
        if (visited[v] == false) {
            DFSUtil(n, edgeList, v, visited);
            count += 1;
        }
    }
    return count;
}

void changeEdgeList(int n, int**& edgeList){
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(edgeList[i][j]==0 && i!=j){
        edgeList[i][j]=INT_MAX;
      }
    }
  }
}

void allPairs(int n, int**& edgeList, double*& scores){
  int a, b, i, j, k;
  for(k=0; k<n; k++){
    for(i=0; i<n; i++){
      for(j=0; j<n; j++){
          a=edgeList[i][j];
          if(edgeList[i][k]==INT_MAX || edgeList[k][j]==INT_MAX) b=INT_MAX;
          else b=edgeList[i][k]+edgeList[k][j];
          edgeList[i][j]=a<b?a:b;
      }
    }
  }
  for(k=0; k<n; k++){
    scores[k]=0;
    for(i=0; i<n; i++){
      for(j=0; j<n; j++){
        if(i==k || j==k){
          continue;
        }
        else if(i==j){
          if(edgeList[i][k]==INT_MAX || edgeList[k][j]==INT_MAX){
            continue;
          }
          else{
            scores[k]+=edgeList[i][k]+edgeList[k][j];
          }
        }
        else{
          if(edgeList[i][k]==INT_MAX || edgeList[k][j]==INT_MAX || edgeList[i][j]==INT_MAX){
            continue;
          }
          else{
            scores[k]+=double(edgeList[i][k]+edgeList[k][j])/double(edgeList[i][j]);
          }
        }
      }
    }
  }
}
// INPUT :
//            n         : number of nodes in the graph
//            edgeList  : edges in the graph
//            scores    : importance scores
// return value :
//                 number of disconnected components
int Important (int n, int**& edgeList, double*& scores){
  changeEdgeList(n, edgeList);
  allPairs(n, edgeList, scores);
  return numberOfComponents(n, edgeList);
}
