#include <bits/stdc++.h>
using namespace std;

int n,e,a,b;
vector<int> g[205];
bool visited[205];
int color[205];
bool ans;

void checkBipartite(int v, int c1, int c2){
  if(!ans) return;
  visited[v] = true;
  color[v] = c1;
  for(int i = 0; i < g[v].size(); i++){
    if(visited[g[v][i]] && color[g[v][i]] == c1){
      ans = false;
      return;
    }
    if(!visited[g[v][i]]){
      checkBipartite(g[v][i],c2,c1);
    }
  }
}

int main(){
  while(cin >> n, n){
    cin >> e;
    for(int i = 0; i < 205; i++) g[i].clear();
    while(e--){
      cin >> a >> b;
      g[a].push_back(b);
    }
    ans = true;
    memset(visited,0,sizeof(visited));
    memset(color,0,sizeof(color));

    checkBipartite(0,1,2);
    if(!ans) cout << "NOT ";
    cout << "BICOLORABLE." << endl;
  }
  return 0;
}