#include <bits/stdc++.h>
using namespace std;

class BIT{
  private:
  vector<int> bit;
  int n;

  public:
  BIT(int arr[], int n_){
    bit = vector<int>(n+1);
    n = n_;
    for(int i = 1; i <=n; i++){
      update(i,arr[i]);
    }
  }
  void print(){
    for(int i = 0; i <=n; i++){
      cout << bit[i] << " ";
    }
    cout << endl;
  }
  int query(int idx){
    int ans = 0;
    while(idx > 0){
      ans += bit[idx];
      idx -= idx & (-idx);
    }
    return ans;
  }
  int update(int idx, int val){
    while(idx<=n){
      bit[idx] += val;
      idx += idx & (-idx);
    }
  }
  int update(int i, int inc, int n){
    while(i <= n){
      bit[i] += inc;
      i += i & (-i);
    }
  }
};

int main(){
  int n; cin >> n;
  int arr[n+1];
  for(int i = 1; i <= n; i++){
    cin >> arr[i];
  }
  BIT ft(arr, n);
  ft.print();
  int q; cin >> q;
  while(q--){
    int a, b; 
    cin >> a >> b;
    cout << ft.query(b) - ft.query(a-1) << endl; 
  }

  return 0;
}