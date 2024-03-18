#include <bits/stdc++.h>
using namespace std;

int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

char arr[105][105];
int n, m;

void floodfill(int r, int c, char c1, char c2)
{
  if (r < 0 || r >= n || c < 0 || c >= m)
    return ;
  if (arr[r][c] != c1)
    return ;
  arr[r][c] = c2;
  for (int i = 0; i < 8; i++)
  {
    if (arr[r + dr[i]][c + dc[i]] == c1)
      floodfill(r + dr[i], c + dc[i], c1, c2);
  }
}

int main()
{
  while (cin >> n, n)
  {
    cin >> m;
    int cont =0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cin >> arr[i][j];
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if(arr[i][j]=='@'){
          cont++;
          floodfill(i, j, '@', '.');
        }
      }
    }
    cout << cont << endl;
  }
  return 0;
}