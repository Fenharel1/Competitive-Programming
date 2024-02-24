#include <bits/stdc++.h>
using namespace std;
int n,m,s, stickers=0;
char rally[105][105];
char instructions[50005];
pair<int,int> pos;
int dir;

/*
dir:
0 -> N
1 -> L
2 -> S
3 -> O

N (-1,0)
L (0, 1)
S ( 1,0)
O (0,-1)
*/
int dr[] = {-1,0,1,0};
int cr[] = {0,1,0,-1};

void proces_input(){
  for(int i = 0; i < s; i++){
    if(instructions[i]=='F'){
      int new_y = pos.first+dr[dir];
      int new_x = pos.second+cr[dir];
      if( new_y < 0 || new_y >=n || new_x < 0 || new_x >= m) continue;
      if(rally[new_y][new_x]=='#') continue;
      if(rally[new_y][new_x]=='*'){
        stickers++;
        rally[new_y][new_x] = '.';
      }
      pos.first = new_y;
      pos.second = new_x;
    }else if(instructions[i]=='D'){ // turn right
      dir = dir+1;
      if(dir==4)dir=0;
    }else if(instructions[i]=='E'){ // turn left
      dir = dir-1;
      if(dir==-1)dir=3;
    }
  }
}

int main(){
  while(cin >> n >> m >> s){
    if(n==0 && m==0 && s==0) break;
    stickers = 0;
    memset(rally,0,sizeof(rally));    
    for(int i = 0; i < n; i++){
      string row; cin >> row;
      for(int j = 0; j < m; j++){
        rally[i][j] = row[j];
        if(rally[i][j]=='N'){
          pos.first = i; pos.second = j;
          dir = 0;
        }
        if(rally[i][j]=='L'){
          pos.first = i; pos.second = j;
          dir = 1;
        }
        if(rally[i][j]=='S'){
          pos.first = i; pos.second = j;
          dir = 2;
        }
        if(rally[i][j]=='O'){
          pos.first = i; pos.second = j;
          dir = 3;
        }
      }
    }
    string all_instructions;
    cin >> all_instructions;
    for(int i = 0; i< s; i++) instructions[i] = all_instructions[i];

    proces_input();
    cout << stickers << endl;
  }
  return 0;
}