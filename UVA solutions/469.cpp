#include <bits/stdc++.h>
using namespace std;

char florida[105][105];
int R, C;

int dr[] = {1,1,0,-1,-1,-1,0,1};
int dc[] = {0,1,1,1,0,-1,-1,-1};

int floodfill(int r, int c, char c1, char c2){
  if(r < 0 || r >= R || c < 0 || c >= C) return 0;
  if(florida[r][c]!=c1) return 0;
  florida[r][c] = c2;
  int ans = 1;
  for(int i = 0; i < 8; i++)
    ans += floodfill(r+dr[i],c+dc[i],c1,c2);
  return ans;
}
void restaurar(){
  for(int i = 0; i < R; i++){
    for(int j = 0; j < C; j++){
      florida[i][j] = florida[i][j]=='.'?'W':florida[i][j];
    }
  }
}

int main(){
  int tc;
  cin >> tc;
  cin.ignore();
  cin.ignore();

  while(tc--){
    char str[105];
    R = 0; C = 0;
    while(cin.getline(str,100)){
      if(strlen(str)==0) break;
      else if(str[0]=='L'||str[0]=='W'){
        C = strlen(str);
        for(int i = 0; i < C; i++) florida[R][i] = str[i];
        R++;
      }else{
        restaurar();
        stringstream stream(str);
        int i, j;
        stream >> i >> j;
        cout << floodfill(i-1,j-1,'W','.') << endl;
      }
    }
    if(tc) cout << endl;
  }
  return 0;
}