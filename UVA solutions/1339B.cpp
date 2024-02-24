#include <bits/stdc++.h>
using namespace std;

int main(){
  int tc; cin >> tc;
  while(tc--){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i< n; i++) cin >> arr[i];
    sort(arr, arr+n);
    
    if(n%2!=0) cout << arr[n/2] << " ";
    
    for(int i = n/2-1; i >= 0; i--){
      cout << arr[i] << " " << arr[n-1-i] << " ";
    }
    cout << endl;
  }
  return 0;
}