#include <bits/stdc++.h>
using namespace std;

int main(){
  int tc;
  cin >> tc;
  while(tc--){
    int _a,_b,n; cin >> _a >> _b >> n;
  
    int b = max(_a,_b), a = min(_a,_b);
    int cont = 0;
    while(a <= n && b <= n){
      cont++;
      if(cont % 2 == 0) b += a;
      else a += b;
    }
    cout << cont << endl;
  }
  return 0;
}