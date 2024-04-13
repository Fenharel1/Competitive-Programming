#include <bits/stdc++.h>
using namespace std;

int n;

vector<int> g[205];
bool visited[205];
int color[205];

int cont1, cont2;
bool valid;
void dfs(int v, int c1, int c2)
{
  visited[v] = true;
  color[v] = c1;

  for (int i = 0; i < g[v].size(); i++)
  {
    if(visited[g[v][i]] && color[g[v][i]] == c1){
      valid = false;
    }
    if (!visited[g[v][i]])
      dfs(g[v][i], c2, c1);
  }
}

int main()
{
  int tc;
  cin >> tc;
  while (tc--)
  {
    cin >> n;
    for (int i = 0; i < 205; i++)
      g[i].clear();
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < n; i++)
    {
      int p;
      cin >> p;
      while (p--)
      {
        int x;
        cin >> x;
        g[i].push_back(x - 1);
        g[x - 1].push_back(i);
      }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      if (!visited[i])
      {
        memset(color, -1, sizeof(color));

        cont1 = 0;
        cont2 = 0;
        valid = true;
        dfs(i, 1, 0);

        for(int j = 0; j < n; j++) 
          if(color[j] == 1) cont1++;
          else if(color[j] == 0) cont2++;

        ans += valid?max(cont1, cont2):0;
      }
    }
    cout << ans << endl;
  }

  return 0;
}