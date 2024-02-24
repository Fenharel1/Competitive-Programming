#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n, m;
  long long max = 0, min = 0;
  cin >> n >> m;
  long long aux = n-(m-1);
  max = (aux-1)*aux/2;
  long long q = n/m;
  long long r = n%m;
  min += (r)*((q+1)*(q))/2;
  min += (m-r)*(q*(q-1))/2;
  cout << min << " " << max;
  return 0;
}