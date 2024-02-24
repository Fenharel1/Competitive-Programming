#include <bits/stdc++.h>
using namespace std;

int main(){ 
  int n, m;
  cin >> n >> m;
  int arr[m];
  for(int i = 0; i < m; i++) cin >> arr[i];
  sort(arr, arr+m);

  int mini = 1000000;
  for(int  i = 0; i <= m - n; i++){
    mini = min(mini, arr[i+n-1] - arr[i]);
  }
  cout << mini << endl;
  return 0;
}
