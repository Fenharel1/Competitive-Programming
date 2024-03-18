#include <bits/stdc++.h>
using namespace std;

int dr2[] = {1, 0, -1, 0};
int dc2[] = {0, 1, 0, -1};

char arr[105][105];
int n, m;
int dot = 0;

void floodfill(int r, int c, char c1, char c2)
{
  if (r < 0 || r >= n || c < 0 || c >= m)
    return;
  if (arr[r][c] == 'X' && c1 != 'X')
  {
    floodfill(r, c, 'X', '*');
    dot++;
  }
  if (arr[r][c] != c1)
    return;
  arr[r][c] = c2;
  for (int i = 0; i < 4; i++)
  {
    floodfill(r + dr2[i], c + dc2[i], c1, c2);
  }
}

int main()
{
  int TC = 1;
  while (cin >> m >> n, (n && m))
  {
    vector<int> dots;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cin >> arr[i][j];
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (arr[i][j] == '*')
        {
          dot = 0;
          floodfill(i, j, '*', '.');
          dots.push_back(dot);
        }
      }
    }
    sort(dots.begin(), dots.end());
    cout << "Throw " << TC++ << endl;
    for (int i = 0; i < dots.size(); i++)
    {
      if (i != 0)
        cout << " ";
      cout << dots[i];
    }
    cout << endl
         << endl;
  }
  return 0;
}