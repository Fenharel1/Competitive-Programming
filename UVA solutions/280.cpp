#include <bits/stdc++.h>
using namespace std;

vector<int> g[100000];
int visited[100000];
int visitedCnt = 0;

void dfs(int v, bool flag = false){
  if(flag) visited[v] = 1;
  for(int i = 0; i < g[v].size(); i++){
    if(visited[g[v][i]]) continue;
    dfs(g[v][i],true);
  }
}

int main(){
  int n;
  while(cin >> n,n){
    for(int i = 0; i <= n; i++) g[i].clear();
    int v;
    while(cin >> v,v){
      int u;
      while(cin >> u, u) {
        g[v].push_back(u);
      }
    }
    int q; cin >> q;
    for(int i = 0; i < q; i++){
      int vertex; cin >> vertex;
      memset(visited, 0, sizeof(visited));
      dfs(vertex);
      int cont = 0;
      for(int i = 1; i <= n; i++){
        if(visited[i]==0) cont++;
      }
      cout << cont;
      for(int i = 1; i <= n; i++){
        if(visited[i]==0) cout << " " << i;
      }
      cout << endl;
    }
  }
  return  0;
}