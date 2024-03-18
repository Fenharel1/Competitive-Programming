#include <bits/stdc++.h>

using namespace std;

#define ii pair<int,int>

vector<ii> g[105];
int visited[105];
int cnt = 0, finish = 0;
int values[105];

bool customCompare(ii a, ii b) {
  return a.second < b.second; // Change to a > b for descending order
}

void dfs(int v){
  visited[v] = 1;
  finish = v;
  if(g[v].size() == 0) return;
  ii maxNeighbor = *(max_element(g[v].begin(), g[v].end(),customCompare));
  if(visited[maxNeighbor.first]==0){
    cnt+=maxNeighbor.second;
    dfs(maxNeighbor.first);
  }
}

void show(int n){
  for(int i = 0; i < n; i++){
    cout << i << " : ";
    for(int j = 0; j < g[i].size(); j++) cout << g[i][j].first << " ";
    cout << endl;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int tc; cin >> tc;
  int TC = 1;
  register int n, m, a,b;
  while(tc--){
    cin >> n >> m;
    memset(values,0,sizeof(values));
    memset(visited,0,sizeof(visited));
    cnt = 0; finish = 0;
    for(int i = 0; i < n; i++) g[i].clear();

    for(int i = 0; i < n; i++) cin >> values[i];
    while(m--){
      cin >> a >> b;
      g[a].push_back(make_pair(b,values[b]));
    }

    // show(n);
    dfs(0);
    cout << "Case " << TC++ << ": " << cnt << " " << finish << endl;
  }
  return 0;
}