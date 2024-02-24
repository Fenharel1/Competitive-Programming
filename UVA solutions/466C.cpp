#include <bits/stdc++.h>
using namespace std;

int dp[1000005];

int main(){
  int n; cin >> n;
  int sumTotal = 0;
  int aux;
  memset(dp, 0, sizeof(dp));
  for(int i = 0; i < n; i++){ 
    cin >> aux;
    sumTotal += aux;
    dp[i] = sumTotal;
  }

  long long ways = 0;
  int cont1 = 0, cont2 = 0;

  vector<int> idxI;
  vector<int> idxJ;

  for(int i = 1; i < n-1; i++){
    if(dp[i-1]*3==sumTotal) idxI.push_back(i);
    if(dp[i]*3==sumTotal*2) idxJ.push_back(i);
  }

  for(int i = 0; i < idxI.size(); i++){
    int aux = lower_bound(idxJ.begin(), idxJ.end(), idxI[i]) - idxJ.begin();
    ways += idxJ.size() - aux;
  }

  cout << ways << endl;
  
  return 0;
}