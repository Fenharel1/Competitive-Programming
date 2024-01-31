#include <bits/stdc++.h>
using namespace std;
int main(){
  int tc; cin >> tc;
  int TC = tc;
  while(tc--){
    if(tc != TC -1) cout << endl;
    int n, k; cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; i++) arr[i] = 1;
    while(k--){
      int p; cin >> p;
      p = p * 2;
      int brr[p];
      for(int i = 0; i < p; i++){
        cin >> brr[i];
      }
      char st; cin >> st;
      if(st == '='){
        for(int i = 0; i < p; i++) arr[brr[i] - 1] = 0;
      }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++) cnt+=arr[i];
    if(cnt == 1){
      for(int i = 0; i < n; i++) if(arr[i] == 1) cout << i+1 << endl ;
    }else{
      cout << 0 << endl ;
    }

  }
  return 0;
}