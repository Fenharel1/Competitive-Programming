#include <bits/stdc++.h>
using namespace std;

long long start[64005];

int main(){
  for(long long i = 0; i < 64005; i++) start[i] = 3000000000;
  start[0] = 1;
  long idx = 1;
  while(start[idx-1] <= 2000000000){
    start[idx] = start[idx-1] + idx;
    idx++;
  }
  
  int tc;
  cin >> tc;
  while(tc--){
    long long n, k; cin >> n >> k;
    long long idxLower = lower_bound(start, start+64000,k) - start;
    if(start[idxLower]!=k) idxLower--;
    for(long long i = 0; i < n; i++){
      if(i == n - (idxLower + 2) || i == n - (k - start[idxLower]) - 1) cout << 'b';
      else cout << 'a';
    }
    cout << endl;
  }
  
  return 0;
}