#include <bits/stdc++.h>
#define Rep(i,n) for(i = 0; i < n; i++);
using namespace std;

int main(){
  int tc; cin >> tc;
  int inputs[5] = {1,3,5,7,9}; 
  while(tc--){
    int m[12][12];
    memset(m,0,sizeof(m));
    for(int i = 0; i < 5; i++){
      for(int j = 0; j < inputs[i]; j+=2){
        cin >> m[inputs[i]-1][j];
      }
    }
    
    for(int i = 8; i > 0; i--){
      if(i%2!=0){
        for(int j = 0; j < i+1; j++){
          m[i][j] = m[i+1][j] + m[i+1][j+1];
        }
      }else{
        for(int j = 1; j < i+1; j+=2){
          m[i][j] = m[i-2][j-1] - (m[i][j-1] + m[i][j+1]);
          m[i][j] /= 2;
        }
      }
    }

    for(int i = 0; i < 9; i++){
      for(int j = 0; j < i+1; j++){
        if(j!=0) cout << " ";
        cout << m[i][j];
      }
      cout << endl;
    }
  }
  return 0;
}