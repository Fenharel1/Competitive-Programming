#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--){
    int n; cin >> n;
    int arr[n];
    map<int, int> freq;
    for(int i = 0; i < n; i++){
      cin >> arr[i];
      freq[arr[i]]++;
    } 
    if(freq.size() < 2){
      cout << -1 << endl;
      continue;
    }

    int b[n];
    memset(b, 0, sizeof(b));

    int aux = 0;
    for(auto it = freq.begin(); it != freq.end(); it++){
      if(it->second > 1){
        aux++;
        int count = 2;
        for(int i = 0; i < n; i++){
          if(count == 0) break;
          if(arr[i] != it->first) continue;
          b[i] = count==2?1:(aux==1?2:3);
          count --;
        }
        if(aux==2) break; 
      }
    }
    if(aux != 2){
      cout << -1 << endl;
      continue;
    } 
    for(int i = 0; i < n; i++){
      if(b[i] == 0) b[i] = 1;
    }

    for(int i = 0; i < n; i++){
      cout << b[i] << " " ;
    }

    cout << endl;
  }
  return 0;
}