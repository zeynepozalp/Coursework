#include <iostream>
#include <fstream>
#include <queue>
#include <climits>

using namespace std;

void readParams(ifstream& file, int& n, int**& edgelist){
	std::string size;
	getline(file,size);
	n=stoi(size);
	edgelist=(int**)malloc(sizeof(int*)*n);
	int j;
	int i=0;
	while(getline(file,size)&& i<n){
		std::string append="";
		j=0;
		int* row=new int[n];
		for(char i:size){
			if(i==' ' && j<n){
				row[j]=stoi(append);
				j++;
				append="";
				continue;
			}
			append+=i;
		}
		row[j]=stoi(append);
		edgelist[i]=row;
		i++;
	}
}

void printMatrix(int& n, int** edgelist){
  int i, j;
  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      cout << edgelist[i][j] << " ";
    }
    cout << endl;
  }
}

void printVector(int& n, int* vec){
  int j;
    for(j=0; j<n; j++){
      cout << vec[j] << " ";
    }
    cout << endl;
}

void BFS(int s, int& n, int** edgelist){
  bool* visited = new bool[n];

  int i;
  for(i=0; i<n; i++) visited[i]=false;

  deque<int> que;
  visited[s]=true;
  que.push_back(s);

  while(!que.empty()){
    s=que.front();
    cout << s << " ";
    que.pop_front();

    for(i=0; i<n; i++){
      if(edgelist[s][i]){
        if(!visited[i]){
          visited[i]=true;
          que.push_back(i);
        }
      }
    }
  }
  cout << endl;
}

void DFSUtil(int s, int& n, int** edgelist, bool* visited){
  visited[s] = true;
  int i;
  cout << s << " ";
  for (i=0; i<n; i++){
    if(edgelist[s][i]){
        if(!visited[i]){
            DFSUtil(i, n, edgelist, visited);
        }
    }
  }
}

void DFS(int s, int& n, int** edgelist){
  bool* visited = new bool[n];

  int i;
  for(i=0; i<n; i++) visited[i]=false;

  DFSUtil(s,n,edgelist, visited);
  cout << endl;
}

void printMST(int n, int parent[], int key[]){
  cout<<"Edge \tWeight\n";
  for (int i = 1; i < n; i++)
      cout<<parent[i]<<" - "<<i<<" \t"<<key[i]<<" \n";
}

int minKey(int n, int key[], bool mstSet[]){
  int min = INT_MAX, min_index;
    for (int v = 0; v < n; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void PrimMST(int n, int** edgelist){
  int i, v;
  // Array to store constructed MST
  int parent[n];

  // Key values used to pick minimum weight edge in cut
  int key[n];

  // To represent set of vertices not yet included in MST
  bool mstSet[n];

  for (i = 0; i < n; i++){
    key[i] = INT_MAX;
    mstSet[i] = false;
  }

  key[0] = 0;
  parent[0] = -1;

  for(i=0; i<n-1; i++){
    int u = minKey(n, key, mstSet);
    mstSet[u] = true;

    for(v=0; v<n; v++){
        if(edgelist[u][v] && mstSet[v] == false && edgelist[u][v] < key[v]){
            parent[v] = u;
            key[v] = edgelist[u][v];
        }
    }
  }

  printMST(n, parent, key);
}

int minDistance(int n, int pathSet[], bool sptSet[]){
	int i, min=INT_MAX, min_index;
	for(i=0; i<n; i++){
		if(!sptSet[i] && pathSet[i]<min){
			min=pathSet[i];
			min_index=i;
		}
	}
	return min_index;
}

void printDSP(int n, int pathSet[], int parents[]) {
	int i;
	cout << "Vertex\tDistance\tPath" << endl;
	for(i=0; i<n; i++){
		cout << i << "\t" << pathSet[i] << "\t";
		cout << i << " <- ";
		int parent = parents[i];
		while(parent!=-1){
			cout << parent;
			if(parent) cout << " <- ";
			parent=parents[parent];
		}
		cout << endl;
	}
}

void DijkstraSP(int n, int** edgelist){
	int pathSet[n];
	bool sptSet[n];
	int parent[n];

	int i;
	for(i=0; i<n; i++){
		sptSet[i]=false;
		pathSet[i]=INT_MAX;
	}

	pathSet[0]=0;
	parent[0]=-1;

	for(i=0; i<n; i++){
		int u, v;
		u=minDistance(n, pathSet, sptSet);

		sptSet[u]=true;
		for(v=0; v<n; v++){
			if(!sptSet[v] && edgelist[u][v] && pathSet[u]+edgelist[u][v]<pathSet[v]){
				pathSet[v]=pathSet[u]+edgelist[u][v];
				parent[v]=u;
			}
		}
	}
	//printVector(n, parent);
	//printVector(n, pathSet);
	printDSP(n, pathSet, parent);
}

void allPairs(int n, int** edgelist){

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if(i!=j && edgelist[i][j]==0 && k==0){
					edgelist[i][j]=INT_MAX;
				}
				else{
					if(edgelist[i][k]!=INT_MAX && edgelist[k][j]!=INT_MAX){
						int a=edgelist[i][j];
						int b=edgelist[i][k]+edgelist[k][j];
						edgelist[i][j]=a<b?a:b;
					}
				}
			}
		}
	}
	printMatrix(n, edgelist);
}

bool maxFlowBFS(int n, int** edgelist, int parent[]){
	int s=0, t=5;
	bool* visited = new bool[n];

  int i;
  for(i=0; i<n; i++) visited[i]=false;

  deque<int> que;
  visited[s]=true;
  que.push_back(s);
	parent[s]=-1;

  while(!que.empty()){
    s=que.front();
    que.pop_front();

    for(i=0; i<n; i++){
      if(edgelist[s][i] && !visited[i]){
        visited[i]=true;
        que.push_back(i);
				parent[i]=s;
      }
    }
  }
	return (visited[t] == true);
}

void maxFlow(int n, int** edgelist){
	int s = 0, t = 5;

	int i,j;

	int** rGraph = new int*[n];

	for (i = 0; i < n; i++) {
		int* row = new int[n];
		for (j = 0; j < n; j++) {
			row[j]=edgelist[i][j];
		}
		rGraph[i]=row;
	}

	int parent[n];  // This array is filled by BFS and to store path
  int max_flow = 0;

	while(maxFlowBFS(n, rGraph, parent)){
		int pathFlow = INT_MAX;
		int u, v;

		for(v=t; v!=s; v=parent[v]){
      u = parent[v];
      pathFlow = rGraph[u][v]<pathFlow?rGraph[u][v]:pathFlow;
    }

		for(v=t; v != s; v=parent[v]){
      u = parent[v];
      rGraph[u][v] -= pathFlow;
      rGraph[v][u] += pathFlow;
    }

		max_flow += pathFlow;
	}

	cout << "Max Flow from " << s << " to " << t << " is " << max_flow << endl;
}

int main(){
  ifstream file1("input1.txt");
  int** edgelist;
  int n=0;
  if(file1){
    readParams(file1,n,edgelist);
    file1.close();
  }

  cout << "-------Printing matrix------" << endl;
  printMatrix(n, edgelist);
  cout << "-------Calling BFS------" << endl;
  BFS(0, n, edgelist);
  cout << "-------Calling DFS------" << endl;
  DFS(0,n,edgelist);

  ifstream file2("input2.txt");
  n=0;
  if(file2){
    readParams(file2,n,edgelist);
    file2.close();
  }

  cout << "-------Printing matrix------" << endl;
  printMatrix(n, edgelist);
  cout << "-------Calling Prim's MST------" << endl;
  PrimMST(n, edgelist);

	ifstream file3("input3.txt");
  n=0;
  if(file3){
    readParams(file3,n,edgelist);
    file3.close();
  }
	cout << "-------Printing matrix------" << endl;
  printMatrix(n, edgelist);
	cout << "-------Calling Dijkstra's SP------" << endl;
	DijkstraSP(n, edgelist);
	cout << "-------Calling All Pairs SP------" << endl;
	allPairs(n, edgelist);

	ifstream file4("input4.txt");
  n=0;
  if(file4){
    readParams(file4,n,edgelist);
    file3.close();
  }
	cout << "-------Printing matrix------" << endl;
  printMatrix(n, edgelist);
	cout << "-------Calling Max Flow------" << endl;
	maxFlow(n, edgelist);
  return 0;
}
