#include <bits/stdc++.h>
#define MAX 4000
using namespace std;

int coins[MAX];
int memo[MAX][500]; // 500 is the max of value
int value, n;

int Solve(int type, int value){
  if(value == 0) return 1;
  if(value < 0) return 0;
  if(type==n) return 0;
  if(memo[type][value] != -1) return memo[type][value];
  return memo[type][value] = Solve(type+1, value) + Solve(type, value - coins[type]);
}

int main(){
  memset(memo, -1, sizeof(memo));
  cin >> n >> value;
  for(int i = 0; i < n; i++){
    cin >> coins[i];
  }
  printf("Solution: %d\n", Solve(0,value));
  return 0;
}