#include <bits/stdc++.h>
using namespace std;

bool cmp(const string &a, const string &b){
  return a + b > b + a;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  register string numbers[55];

  register int n;
  register int i = 0;
  while(cin >> n, n ){
    for(i = 0; i < n; i++) cin >> numbers[i];

    sort(numbers,numbers+n,cmp);

    for(i = 0; i < n; i++) cout << numbers[i];
    cout << '\n';
  }
  return 0;
}