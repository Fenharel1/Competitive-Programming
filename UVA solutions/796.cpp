#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;


const int MAX = 10000;
const int UNVISITED = -1;

vi g[MAX];
int num[MAX];
int low[MAX];
int parent[MAX];
int it;

vector<pair<int,int>> ans;

void dfs(int v){

  num[v] = low[v] = it++;

  for(int i = 0; i < g[v].size(); i++){
    int u = g[v][i];
    if(num[u] == UNVISITED){
      parent[u] = v;
      dfs(u);
      if(low[u] > num[v]){
        ans.push_back({min(u,v),max(u,v)});
      }
      low[v] = min(low[v], low[u]);
    }else if(u != parent[v]){
      low[v] = min(low[v], num[u]);
    }
  }
}

int main(){
  int n;
  while(cin >> n){
    for(int i = 0; i < n; i++) g[i].clear();
    int q = n;
    while(q--){
      int v, p, x; 
      char dummy; 
      cin >> v >> dummy >> p >> dummy;
      while(p--){
        cin >> x;
        g[v].push_back(x);
        g[x].push_back(v);
      }
    }

    memset(num,UNVISITED,sizeof(num));
    memset(low,0,sizeof(0));
    memset(parent,0,sizeof(parent));
    ans.clear();
    it=0;
    for(int i = 0; i < n; i++){
      if(num[i] == UNVISITED){
        dfs(i);
      }
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << " critical links" << endl;
    for(int i = 0; i < ans.size(); i++){
      cout << ans[i].first << " - " << ans[i].second << endl;
    }
    cout << endl;
  }
  return 0;
}