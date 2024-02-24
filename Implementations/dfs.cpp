// dfs for a matrix of adjacency
#include <bits/stdc++.h>
using namespace std;
#define MAX 100


int graph[MAX][MAX];
int n;
bool visited[MAX];

void dfs(int node){
  visited[node] = true;
  for(int i = 0; i < n; i++)
    if(!visited[i]) dfs(i);
}

int main(){
  return 0;
}