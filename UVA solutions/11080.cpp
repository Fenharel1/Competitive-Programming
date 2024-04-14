#include <bits/stdc++.h>
#define pb push_back
#define allo(arr, v) memset(arr, v, sizeof(arr));
using namespace std;
typedef vector<int> vi;

int n,e,a,b;
vi g[205];
bool visited[205];
int color[205];
bool flag;

int bfs(int s){
  allo(color,-1);

  visited[s] = true;
  color[s] = 1;
  queue<int> q;
  q.push(s);

  while(!q.empty()){
    int u = q.front(); q.pop();
    for(int i = 0; i < g[u].size(); i++){
      int v = g[u][i];
      if(!visited[v]){
        visited[v] = true;
        color[v] = 1 - color[u];
        q.push(v);
      }else if(color[v] == color[u]){
        flag = false;
        return 0;
      }
    }
  }

  int op1 = 0, op2 = 0;
  for(int i = 0; i < n; i++){
    if(color[i] == 1) op1++;
    if(color[i] == 0) op2++;
  }
  return min(op1,op2)==0?1:min(op1,op2);

}

int main(){
  int tc;
  cin >> tc;
  while(tc--){

    for(int i = 0; i < n; i++) g[i].clear();

    cin >> n >> e;
    while(e--){
      cin >> a >> b;
      g[a].pb(b);
      g[b].pb(a);
    } 

    allo(visited, false);

    flag = true;
    int ans = 0;
    for(int i = 0; i < n && flag; i++){
      if(!visited[i])
        ans += bfs(i);
    }
    if(!flag) cout << -1 << endl;
    else cout << ans << endl;
    
  }
  return 0;
}