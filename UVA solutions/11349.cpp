#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc; 
  cin >> tc;
  cin.ignore();
  long long arr[105][105];
  char aux, aux2; 
  int n, TC = 1; 
  bool sym = true;
  string str;
  int i = 0, j = 0;
  while(tc--){
    cin >> aux >> aux2 >> n;
    sym = true;
    for(i = 0; i < n; i++){
      if(!sym){
        cin.ignore();
        getline(cin, str);
      }else{
        for(j = 0; j < n ; j++){ 
          cin >> arr[i][j] ;
          if(!sym) continue;
          if(arr[i][j] < 0) sym = false;
          if(i>=n/2){
            if(n%2!=0 && i == n/2 && j < n/2) continue;
            if(arr[i][j] != arr[abs(n-i-1)][abs(n-j-1)]){sym = false;}
          }
        }
      }
    } 
    printf("Test #%d: %s.\n", TC++, (sym ? "Symmetric" : "Non-symmetric"));
  } 
  return 0;
}
