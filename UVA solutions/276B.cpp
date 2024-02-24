#include <bits/stdc++.h>
using namespace std;

int main(){
  string str; cin >> str;

  map<char, int> mp;
  for(int i = 0; i < str.size(); i++){
    mp[str[i]]++;
  }
  int countOdd = 0;
  for(auto it=mp.begin(); it!=mp.end(); it++) if(it->second%2!=0) countOdd++;
 
  if(countOdd <= 1) cout << "First" << endl;
  else if(countOdd % 2 != 0) cout << "First" << endl;
  else cout << "Second" << endl;

  return 0;
}