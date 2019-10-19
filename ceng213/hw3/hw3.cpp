#include "hw3.h"
using namespace std;

int AccessControl::findPrime(int tableSize){
	int n=2*tableSize+1;
	while(n){
		if(isPrime(n)) {return n;}
		n+=2;
	}
}

bool AccessControl::isPrime(int n){
	int s = sqrt(n);
	if(pow(s,2)==n) return false;
	for(int i=3; i<(n/2); i++){
		if(n%i==0) return false;
	}
	return true;
}

bool AccessControl::isChanged(std::string username){
	for(int i=0; i<changed.capacity();i++){
		if(changed[i]==username) return true;
	}
	return false;
}

bool AccessControl::isVisited(std::string username){
	for(int i=0; i<visited.size(); i++){
		if(visited[i]==username) return true;
	}
	return false;
}

void AccessControl::rehash1(){
	std::vector< std::pair<std::string, std::string> > ntable;
	int n=findPrime(table1size);
	std::pair<std::string, std::string> a;
	a.first=EMPTY; a.second=EMPTY;
	ntable.resize(n, a);
	for(int i=0; i<table1size; i++){
		if(table1[i].first!=EMPTY && table1[i].first!=DELETED && !isVisited(table1[i].first)){
			if(!isChanged(table1[i].first)){
				for(int j=0; j<n; j++){
					int h=hashFunction(table1[i].first, n, j);
					if(ntable[h].first==EMPTY){
						ntable[h].first=table1[i].first;
						ntable[h].second=table1[i].second;
						break;
					}
				}
			}
			else{
				for(int j=0; j<table1size; j++){
					int h1=hashFunction(table1[i].first, table1size, j);
					if(table1[h1].first==table1[i].first){
						for(int k=0; k<n; k++){
							int h2=hashFunction(table1[i].first, n, k);
							if(ntable[h2].first==EMPTY){
								ntable[h2].first=table1[h1].first;
								ntable[h2].second=table1[h1].second;
								break;
							}
						}
					}
				}
				visited.push_back(table1[i].first);
			}
		}
	}
	visited.clear();
	table1=ntable;
	table1size=n;
}

void AccessControl::rehash2(){
	std::vector<std::string> table;
	int n=findPrime(table2size);
	table.resize(n);
	for(int j=0; j<table2.size(); j++){
		if(table2[j]!=EMPTY && table2[j]!=DELETED){
			int i=0, k=0;
			while(k<n){
				int hOld=hashFunction(table2[j], table2size, i);
				int hNew=hashFunction(table2[j], n, k);
				if(table[hNew]==""){
					table[hNew]=table2[j];
					break;
				}
				else i++;
				k++;
			}
		}
	}
	for(int l=0; l<n; l++){
		if(table[l]==""){
			table[l]=EMPTY;
		}
	}
	table2=table;
	table2size=n;
}

AccessControl::AccessControl(int table1Size, int table2Size){
	table1.resize(table1Size);
	table2.resize(table2Size);

	this->table1size=table1Size;
	this->table2size=table2Size;
	this->nofUsers=0;
	this->nofActive=0;

	for(int i=0; i<table1Size; i++){
		table1[i].first=EMPTY;
		table1[i].second=EMPTY;
	}
	for(int i=0; i<table2Size; i++){
		table2[i]=EMPTY;
	}
}

AccessControl::~AccessControl(){}

int AccessControl::addUser(std::string username, std::string pass){
	int r=0;
	for(int i=0; i<table1size; i++){
    int h=hashFunction(username, table1size, i);
		if(table1[h].first==username){
			r=0; break;
		}
		else if(table1[h].first==EMPTY || table1[h].first==DELETED){
			table1[h].first=username;
			table1[h].second=pass;
			this->nofUsers++;
			r=1; break;
		}
	}
	if(nofUsers/table1size>MAX_LOAD_FACTOR){
		rehash1();
	}
	return r;
}

int AccessControl::addUsers(std::string filePath){
  ifstream infile(filePath.data());
  string line, username, pass;
  size_t pos;
  int count;
  while(getline(infile,line)){
    pos=line.find(" ");
    username = line.substr(0, pos);
    pass = line.substr(pos+1, line.length());
    if(addUser(username, pass)) count++;
  }
  return count;
}

int AccessControl::delUser(std::string username, std::vector<std::string>& oldPasswords){
  int i,j;
  for(i=0; i<table1size;i++){
    if(table1[i].first==username) break;
  }
  if(i==table1.size()) return 0;
  for(j=0; j<table1size;j++){
    int h=hashFunction(username, table1size, j);
    if(table1[h].first==username){
      table1[h].first=DELETED;
      oldPasswords.push_back(table1[h].second);
      table1[h].second=DELETED;
			nofUsers--;
    }
  }
  return 1;
}

int AccessControl::changePass(std::string username, std::string oldpass, std::string newpass){
	int r=0;
	for(int i=0; i<table1size; i++){
		int h1=hashFunction(username, table1size,i);
		if(table1[h1].first==username && table1[h1].second==oldpass){
			for(int j=0; j<table1size; j++){
				h1=hashFunction(username, table1size,j);
				if(table1[h1].first==EMPTY || table1[h1].first==DELETED){
					table1[h1].first=username;
					table1[h1].second=newpass;
					this->nofUsers++;
					if(!isChanged(table1[h1].first)) changed.push_back(table1[h1].first);
					r=1; break;
				}
			}
		}
	}
	if(nofUsers/table1size>MAX_LOAD_FACTOR) rehash1();
	return r;
}

int AccessControl::login(std::string username, std::string pass){
	int r=0;
	for(int j=0; j<table2size; j++){
		if(table2[j]==username) return 0;
	}
	for(int i=table2size-1; i>=0; i--){
		int h1=hashFunction(username, table1size, i);
		int h2=hashFunction(username, table1size, i+1);
		if(table1[h1].first==username && table1[h1].second==pass){
			if(table1[h2].first==username) continue;
			else{
				for(int j=0; j<table2size; j++){
					int h2=hashFunction(username, table2size, j);
					if(table2[h2]==EMPTY || table2[h2]==DELETED){
						table2[h2]=username;
						nofActive++; r=1; break;
					}
				}
			}
		}
	}
	if(nofActive/table2size>MAX_LOAD_FACTOR){
		rehash2();
	}
	return r;
}

int AccessControl::logout(std::string username){
	for(int i=0; i<table2size; i++){
		if(table2[i]==username){
			table2[i]=DELETED;
			nofActive--;
			return 1;
		}
	}
	return 0;
}

float AccessControl::printActiveUsers(){
  for(int i=0; i<table2size; i++){
		std::cout << table2[i] << std::endl;
	}
	return nofActive/table2size;
}

float AccessControl::printPasswords(){
	for(int i=0; i<table1size; i++){
		std::cout << table1[i].first << " " << table1[i].second << std::endl;
	}
	return nofUsers/table1size;
}
