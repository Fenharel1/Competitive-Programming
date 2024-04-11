#include <bits/stdc++.h>
using namespace std;

int dr[] = {1,1,0,-1,-1,-1, 0, 1};
int dc[] = {0,1,1, 1, 0,-1,-1,-1};
char m[50][50];
int n;

void floodfill(int r, int c, char c1, char c2){
  if(r < 0 || r >= n || c < 0 || c >= n) return;
  if(m[r][c] != c1) return;
  m[r][c] = c2;
  for(int i = 0; i < 8; i++){
    floodfill(r+dr[i],c+dc[i],c1,c2);
  }
}

int main(){
  int tc = 1;
  while ( cin >> n ){
    for(int i = 0; i < n; i++) for(int j = 0 ; j < n; j++) cin >> m[i][j];

    int eagles = 0;
    for(int i = 0; i < n; i++)
      for(int j = 0; j<n;j++){
        if(m[i][j]=='1'){
          eagles++;
          floodfill(i,j,'1','.');
        }
      }
    cout << "Image number " << tc++ << " contains " << eagles << " war eagles." << endl;
  }

  return 0;
}