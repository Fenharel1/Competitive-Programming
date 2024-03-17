#include <bits/stdc++.h>
using namespace std;

int main()
{
  int tc;
  cin >> tc;
  int TC = 1;
  while (tc--)
  {
    if (TC != 1)
      cout << endl;
    int n;
    cin >> n;
    int matrix[n + 5][n + 5];

    int row[n + 5];
    int col[n + 5];
    for (int i = 0; i < n + 5; i++)
      row[i] = col[i] = i;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
      {
        char x;
        cin >> x;
        matrix[i][j] = x - '0';
      }
    int m;
    cin >> m;
    int cont = 0;
    bool transpose = false;
    while (m--)
    {

      string com;
      cin >> com;
      if(com == "row" && transpose) com = "col";
      else if(com == "col" && transpose) com = "row";
      if (com == "row")
      {
        int a, b;
        cin >> a >> b;
        int temp = row[a - 1];
        row[a - 1] = row[b - 1];
        row[b - 1] = temp;
      }
      else if (com == "col")
      {
        int a, b;
        cin >> a >> b;
        int temp = col[a - 1];
        col[a - 1] = col[b - 1];
        col[b - 1] = temp;
      }
      else if (com == "transpose")
      {
        transpose = !transpose;
      }
      else if (com == "inc")
        cont++;
      else if (com == "dec")
        cont--;
    }
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        {
          matrix[i][j] = (matrix[i][j] + cont) % 10;
          if(matrix[i][j] < 0){
            matrix[i][j] = 10 + matrix[i][j];
          }
        }

    cout << "Case #" << TC++ << endl;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (!transpose)
        {
          cout << matrix[row[i]][col[j]];
        }
        else
        {
          cout << matrix[row[j]][col[i]];
        }
      }
      cout << endl;
    }
  }
  cout << endl;
  return 0;
}