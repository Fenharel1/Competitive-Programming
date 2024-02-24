#include <bits/stdc++.h>
using namespace std;

int main(){
  int tc; cin >> tc;
  while(tc--){
    int x, n;
    cin >> n >> x;
    int nodd = 0, neven = 0;
    for(int q,i = 0; i < n; i++){
      cin >> q; (q%2==0)?neven++:nodd++;
    }
    
    if(nodd==0){
      cout << "NO" << endl;
      continue;
    }
    x--;
    nodd--;
    if(x>nodd){
      if(nodd%2!=0)nodd--;
      x-=nodd;
      if(neven>=x) cout << "YES" << endl;
      else cout << "NO" << endl;
    }else{
      if(x%2==0){
        cout << "YES" << endl;
      }else{
        if(neven>0) cout << "YES" << endl;
        else cout << "NO" << endl;
      }
    }
  }
  return 0;
}