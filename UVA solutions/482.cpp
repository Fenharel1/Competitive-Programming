#include <bits/stdc++.h>
using namespace std;

int main(){
  int tc; cin >> tc;
  cin.ignore();
  cin.ignore();
  int TC = 0;
  while(tc--){
    if(TC++ != 0 ) {cout << endl;}
    string str;
    vector<int> pos;
    vector<string> ele;
    bool first = true;
    while(getline(cin, str) && !str.empty()){
      istringstream iss(str);
      if(first){
        int aux;
        while(iss >> aux){pos.push_back(aux);}
      }else{
        string aux;
        ele.resize(pos.size());
        int idx = 0;
        while(iss >> aux){ele[pos[idx++]-1] = aux;}
      }
      first = false;
    }
    for(int i = 0; i < pos.size(); i++){
      cout << ele[i] << endl;
    }
  }
  return 0;
}