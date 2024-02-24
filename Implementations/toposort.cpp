#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define MAX 100
#define REP(i,n) for(i = 0; i < n; i++)

vi ts;
bool visited[MAX];
vi g[MAX];
int n;


void toposort_dfs(int node){
  visited[node] = true;
  for(int i = 0; i < g[node].size(); i++){
    if(!visited[g[node][i]]){
      toposort_dfs(g[node][i]);
    }
  }
  ts.push_back(node);
}

void toposort_bfs(int node){
  
}

int main(){
  return 0;
}