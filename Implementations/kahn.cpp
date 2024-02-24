#include <bits/stdc++.h>
using namespace std;
#define MAX 100
#define vi vector<int>

int n;
vi AdjList[MAX];
int toposort[MAX];

void kahn(int* output){
  int incomingDegree[n];
  memset(incomingDegree, 0, sizeof(incomingDegree));
  for(int i = 0; i < n; i++)
    for(int j = 0; j < AdjList[i].size(); j++)
      incomingDegree[AdjList[i][j]]++;
  
  queue<int> q;
  for(int i = 0; i < n; i++)
    if(incomingDegree[i]==0) q.push(i);
  
  int index = 0;
  while(!q.empty()){
    int v = q.front(); q.pop();
    // toposort[index++] = v;
    *(output+index++) = v;
    for(int j=0; j < AdjList[v].size(); j++){
      incomingDegree[AdjList[v][j]]--;
      if(incomingDegree[AdjList[v][j]]==0){
        q.push(AdjList[v][j]);
      }
    }
  }
  if(index!=n){
    cout << "There was a problem" << endl;
  }
}

int main(){
  int m; //nro de aristas
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    int a,b;
    cin >> a >> b;
    AdjList[a].push_back(b);
  }
  int result[n];
  kahn(result);
  for(int i = 0; i < n; i++) cout << result[i] << " ";
  cout << endl;
  return 0;
}

/*
6
8
2 0
2 4
0 1
0 3
4 3
4 5
5 1
3 1
*/