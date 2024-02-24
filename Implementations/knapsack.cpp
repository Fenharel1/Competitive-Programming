#include <bits/stdc++.h>
#define INF 1<<30;
using namespace std;

int values[100];
int V = 10;
int n = 2;
int coinValue[2] = {1,5};

int change(int value){
  if(value == 0) return 0;
  if(value < 0) return INF;
  if(values[value] != -1) return values[value];
  int ans = 1 + change(value-coinValue[0]);
  for(int i = 1; i < n; i++) 
    ans = min(ans, 1+ change(value-coinValue[i]));
  return values[value] = ans;
}

int main(){
  memset(values,-1,sizeof(values));
  cout << change(10) << endl;
  for(int i = 0; i <= V; i++) cout << values[i] << " ";
  cout << endl;

  return 0;
}