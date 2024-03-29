#include <bits/stdc++.h>
using namespace std;

const int N = 100000;
int n;

int tree[2*N];

void build(int arr[]){
  for(int i = 0; i < n; i++){
    tree[n+i] = arr[i];
  }
  for(int i = n-1; i > 0; i--){
    tree[i] = tree[i<<1] + tree[i<<1 | 1];
  }
}

void update(int p, int value){
  tree[p+n] = value;
  p+=n;
  for(int i = p; i > 1; i >>= 1){
    tree[i>>1] = tree[i] + tree[i^1];
  }
}

int query(int l, int r){
  int res = 0;
  for(l+=n, r+=n; l < r; l >>= 1, r >>= 1){
    if(l&1) res += tree[l++];
    if(r&1) res += tree[--r];
  }
  return res;
}

int main(){
  int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
 
  // n is global
  n = sizeof(a)/sizeof(a[0]);
 
  // build tree
  build(a);
   
  // print the sum in range(1,2) index-based
  cout << query(1, 3)<<endl;
  cout << query(1, 2)<<endl;
  cout << query(3, 6)<<endl;
   
  // modify element at 2nd index
  update(2, 1);
   
  // print the sum in range(1,2) index-based
  cout << query(1, 3)<<endl;
  cout << (11^1) << endl;
  return 0;
}