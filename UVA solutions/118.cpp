#include <bits/stdc++.h>
using namespace std;

// int dr[] = {1,0,-1, 0};
// int dc[] = {0,1, 0,-1};
int dr[] = {1,0,-1, 0};
int dc[] = {0,-1, 0,1};

//  N = 0
// 	W = 1
// 	S = 2
// 	E = 3

int main(){
  int n,m;
  cin >> n >> m;
  n++;
  m++;
  int arr[m+5][n+5];
  for(int i = 0; i < m; i++) for(int j = 0 ; j < n; j++) arr[i][j] = 0;

  int px, py;
  char ori;
  string instructions;
  while(cin >> px >> py >> ori >> instructions){
    bool fall = false;
    for(int i = 0; i < instructions.size(); i++){
      char ins = instructions[i];
      if(ins == 'L' ){
        if(ori == 'N') ori = 'W';
        else if(ori == 'E') ori = 'N';
        else if(ori == 'W') ori = 'S';
        else if(ori == 'S') ori = 'E';
      }else if(ins == 'R'){
        if(ori == 'N') ori = 'E';
        else if(ori == 'E') ori = 'S';
        else if(ori == 'W') ori = 'N';
        else if(ori == 'S') ori = 'W';
      }else{
        int dir;
        if(ori == 'N') dir = 0;
        if(ori == 'W') dir = 1;
        if(ori == 'S') dir = 2;
        if(ori == 'E') dir = 3;

        int npy = py + dr[dir];
        int npx = px + dc[dir];
        if(npx < 0 || npx >= n || npy < 0 || npy >= m) fall = true;
        if(fall && arr[py][px] == 0){
          cout << px << " " << py << " " << ori << " LOST" << endl;
          arr[py][px]=1;
          break;
        }
        if(!fall){
          px = npx;
          py = npy;
        }
        fall = false;
      }
    }
    if(!fall){
      cout << px << " " << py << " " << ori << endl;
    }
  }
  return 0;
}