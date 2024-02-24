#include <bits/stdc++.h>
using namespace std;

int heights[2][100005];

int main() {
  memset(heights, 0, sizeof(heights));
  int n;
  cin >> n;
  long long sumn1 = 0, sumn2 = 0;

  for (int i = 0; i < n; i++) {
    cin >> heights[0][i];
  }
  for (int i = 0; i < n; i++) {
    cin >> heights[1][i];
  }

  long long dp[2][100005];
  dp[0][0] = heights[0][0];
  dp[1][0] = heights[1][0];

  for (int i = 1; i < n; i++) {
    dp[0][i] = max(dp[1][i - 1] + heights[0][i], dp[0][i - 1]);
    dp[1][i] = max(dp[0][i - 1] + heights[1][i], dp[1][i - 1]);
  }

  cout << max(dp[0][n - 1], dp[1][n - 1]) << endl;

  return 0;
}
