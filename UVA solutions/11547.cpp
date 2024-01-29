#include <bits/stdc++.h>
using namespace std;
int main() {
  int tc; cin >> tc;
  while(tc--){
    int n ; cin >> n;
    cout << abs(((n * 567 / 9 + 7492) * 235 / 47 - 498) % 100 / 10) << endl;
  }
  return 0;
}