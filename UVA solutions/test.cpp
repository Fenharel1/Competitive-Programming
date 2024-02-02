#include <bits/stdc++.h>
#define ALL(c) c.begin(), c.end()
#define UNIQ(c) c.resize(unique(ALL(c)) - c.begin())
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int arr[] = {1,2,3,4,5};
  int brr[] = {1,2,6};
  int crr[] = {5};
  vector<int> a(arr, arr+5);
  vector<int> b(brr, brr+3);
  vector<int> c(crr, crr+1);
  vector<int> aux1;
  vector<int> aux2;
  set_intersection(a.begin(), a.end(), b.begin(), b.end(), aux1.begin());
  cout << "hola" << endl;
  for(int i = 0; i < aux1.size(); i++) cout << aux1[i] << " " ;
  cout << endl;
}