// bfs implementation
#include <bits/stdc++.h>
using namespace std;
#define MAX 100
#define INF 100000
typedef vector<int> vi;

int graph[MAX][MAX];
int n;

void bfs(int source){
  vi d(n, INF);
  d[source] = 0;
  queue<int> q; q.push(source);
  while(!q.empty()){
    int u = q.front(); q.pop();
    for(int v = 0; v < n; v++){
      if(graph[u][v]==-1) continue;
      if(d[v]==INF){
        d[v] = d[u] + 1;
        q.push(v);
      }
    }
  }
  int layers = 0;
  for(int i = 0; i < n; i++){
    if(d[i]!=INF) layers = max(layers, d[i]);
  }
  for(int i = 0; i <= layers; i++){
    cout << "Layer " << i << ": ";
    for(int j = 0; j < n; j++){
      if(d[j]==i) cout << j << " ";
    }
    cout << endl;
  }
}

int main(){
  memset(graph, -1, sizeof(graph));
  cin >> n;
  int m;
  cin >> m;
  for(int i = 0; i < n; i++){
    int a,b; cin >> a >> b;
    graph[a][b] = graph[b][a] = 1;
  }
  bfs(5);
  
  return 0;
}

/*
13
16
5 1
5 6
5 10
1 0
1 2
9 10
6 11
0 4
9 8
2 3
11 12
3 7
7 12
2 6
10 11
4 8
*/
