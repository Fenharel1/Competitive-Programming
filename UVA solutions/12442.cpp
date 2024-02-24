#include <bits/stdc++.h>
using namespace std;
#define MAX 50005

int n;
int graph[MAX];
int max_send[MAX];
bool visited[MAX];

int dfs(int v){
  visited[v] = true;
  int ans = 1;
  if(!visited[graph[v]]){
    ans += dfs(graph[v]);
  }
  visited[v] = false;
  return max_send[v]=ans;
}

int main(){
  int tc;
  int TC = 1;
  cin >> tc;
  while(tc--){
    cin >> n;
    for(int i = 0; i < n; i++){
      int a,b; cin >> a >> b;
      a--; b--;
      graph[a]=b;
    }
    memset(max_send,-1,sizeof(max_send));
    memset(visited,false,sizeof(visited));
    int ans = -1, idx = -1;
    for(int i = 0; i < n; i++){
      if(max_send[i]==-1)
        dfs(i);
      if(max_send[i]>ans){
        ans=max_send[i];
        idx=i;
      }
    }
    cout << "Case " << TC++ << ": " << idx+1 << endl;
  }

  return 0;
}