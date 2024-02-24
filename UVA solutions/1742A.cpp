#include <bits/stdc++.h>
using namespace std;

int main(){
  int tc;
  cin >> tc;
  while(tc--){
    int a,b,c; cin >> a >> b >> c;
    if(a+b == c || b +c==a || c+a==b) cout << "YES" << endl;
    else cout << "NO" <<endl;
  }
  return 0;
}