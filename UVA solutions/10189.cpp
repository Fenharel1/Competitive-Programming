#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m, tc = 1;
  while(scanf("%d %d", &n, &m), (n || m)){
    if(tc != 1) cout << endl;
    int arr[n+5][m+5];
    for(int i = 0; i < n+5; i++) for(int j = 0; j < m+5; j++) arr[i][j] = 0;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) {
      char x; cin >> x;
      arr[i][j]= (x=='.'?0:-1);
    }
    int col[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int row[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= m; j++){
        if(arr[i][j] == -1){
          for(int k = 0; k < 8; k++){
            if(arr[i+col[k]][j+row[k]]!=-1){
              arr[i+col[k]][j+row[k]]++;
            }
          }
        }
      }
    }
    cout << "Field #" << tc++ << ":" << endl;
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= m; j++){
        if(arr[i][j] == -1) cout << '*';
        else cout << arr[i][j] ;
      }
      cout << endl;
    }
  }
  return 0;
}