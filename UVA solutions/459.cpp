#include <bits/stdc++.h>
using namespace std;
#define MAX 30
typedef vector<int> vi;

bool visited[MAX];
vi G[MAX];
int n;

int convert(char ch){
  return ch - 'A';
}

void dfs(int node){
  visited[node]=true;
  for(int i = 0; i < G[node].size(); i++){
    if(!visited[G[node][i]]) dfs(G[node][i]);
  }
}

int main(){
  int tc;
  cin >> tc;
  cin.ignore();
  cin.ignore();
  while(tc--){
    char str[4];
    cin.getline(str,2);
    n = convert(str[0])+1;
    
    for(int i = 0; i < n; i++) G[i].clear();

    while(cin.getline(str,4)){
      if(strlen(str)==0){ 
        break;
      }
      G[convert(str[0])].push_back(convert(str[1]));
      G[convert(str[1])].push_back(convert(str[0]));
    }
    int CC = 0;
    memset(visited, false, sizeof(visited));
    for(int i = 0; i < n; i++){
      if(!visited[i]){
        dfs(i); CC++;
      }
    } 
    cout << CC << endl;
    if(tc!=0) cout << endl;
  }
  return 0;
}