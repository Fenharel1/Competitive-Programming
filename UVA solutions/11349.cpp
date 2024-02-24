#include <bits/stdc++.h>
#define REP(i,n) for(i = 0; i < n; i++) 
#define max3(a,b,c) max(a,max(b,c))
using namespace std;

int main(){
  int tc; cin >> tc;
  for(int TC = 1; TC <= tc; TC++){
    char _; cin >> _ >> _;
    int n; cin >> n;
    long m[n][n];
    int i,j;
    REP(i,n){
      REP(j,n){
        cin >> m[i][j];
      }
    }
    bool ans = true;
    if(n%2!=0){
      for(int i = 0; i < n/2; i++){
        if(m[n/2][i] != m[n/2][n-i-1]) ans = false;
        if(m[i][n/2] != m[n-i-1][n/2]) ans = false;
      }
    }
    if(!ans) {
      cout << "Test #" << TC << ": Symmetric." << endl;
      continue;
    }
    for(int i = 0; i < n/2 && ans; i++){
      for(int j = 0; j < n && ans; j++){
        if(m[i][j] != m[n-i-1][n-j-1]) ans = false;
        if(m[n-i-1][n-j-1] != m[i][j]) ans = false;
      }
    }
    if(ans){
      cout << "Test #" << TC << ": Symmetric." << endl;
    }else{
      cout << "Test #" << TC << ": Non-symmetric." << endl;
    }
  }
  return 0;
}