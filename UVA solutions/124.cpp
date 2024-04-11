#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for (i = 0; i < n; i++)

bool isvar[30];
bool visited[30];
int len;
int g[30][30];
vector<string> ans;

void dfs(int v, string path = ""){
  visited[v] = true;  
  int i = 0;
  path += (char)(v+'a');
  REP(i,30){
    if(isvar[i] && i!=v){
      if(visited[i] && g[i][v]==0) { 
        visited[v] = false; // constraint violated
        return;
      } 
      if(!visited[i] && g[v][i]==1){
        dfs(i, path);
      }
    }
  }
  if(path.size() == len) cout << path << endl;
  visited[v] = false;
}

int main()
{
  string varss;
  string conss;
  int i = 0, j = 0;
  int tc = 0;

  while (getline(cin, varss, '\n'))
  {
    if(tc++>0) cout << endl;
    getline(cin, conss, '\n');

    istringstream iss(varss);
    istringstream iss2(conss);
    char aux, aux2;
    memset(isvar,0,sizeof(isvar));
    REP(i, 30) { REP(j, 30) {g[i][j] = 1;}}
    ans.clear();

    len = 0;
    while (iss >> aux)
    {
      isvar[aux-'a'] = 1;
      len++;
    }

    while (iss2 >> aux >> aux2)
    {
      g[aux2 - 'a'][aux - 'a'] = 0;
    }

    for(int i = 0; i < 30; i++){
      if(isvar[i]){
        memset(visited,0,sizeof(visited));
        dfs(i);
      }
    }
  }
  return 0;
}