#include <bits/stdc++.h>
using namespace std;

int main(){
  int tc; cin >> tc;
  while(tc--){
    int a, b, c;
    cin >> a >> b >> c;
    int arr[105];
    for(int i = 0; i < 100; i++) arr[i] = i;
    arr[99] = 99;
    bool canplay = true;
    while(b--){
      int head, tail; cin >> head >> tail;
      arr[head-1] = tail-1;
    }
    int pos[a+5];
    for(int i = 0; i < a+5; i++) pos[i] = 0;
    int player = 0;
    while(c--){
      int roll; cin >> roll;
      if(!canplay){
        player = (player + 1) % a;
        continue;
      }
      pos[player] = arr[min(pos[player] + roll, 99)];
      if(pos[player] >= 99) canplay = false;
      player = (player + 1) % a;
    }
    for(int i = 0; i < a; i++){
      cout << "Position of player " << i+1 << " is " << pos[i]+1 << "." << endl;
    }
  }
  return 0;
}