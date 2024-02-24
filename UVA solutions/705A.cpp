#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  for(int i = 0; i < n; i++){
    if(i%2!=0) cout << "I love ";
    else cout << "I hate ";
    if(i+1 != n) cout << "that ";
  }
  cout << "it" << endl;
  return 0;
}