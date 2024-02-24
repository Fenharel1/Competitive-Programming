#include <bits/stdc++.h>
using namespace std;

int main(){
  string str; cin >> str;

  int pos, pos2;
  pos = str.find("AB");
  if(pos!=string::npos){
    pos2 = str.find("BA", pos+2);
    if(pos2 != string::npos){
      cout << "YES" << endl;
      return 0;
    }
  }

  pos = str.find("BA");
  if(pos!=string::npos){
    pos2 = str.find("AB", pos+2);
    if(pos2 != string::npos){
      cout << "YES" << endl;
      return 0;
    }
  }

  cout << "NO" << endl;


  // for(int i = 0; i < str.size()-1; i++){
  //   if(str[i] == 'A' && str[i+1] == 'B'){
  //     for(int j = i+2; j < str.size()-1; j++){
  //       if(str[j] == 'B' && str[j+1] == 'A'){
  //         cout << "YES" << endl;
  //         return 0;
  //       }
  //     }
  //   }
  // }

  // for(int i = 0; i < str.size()-1; i++){
  //   if(str[i] == 'B' && str[i+1] == 'A'){
  //     for(int j = i+2; j < str.size()-1; j++){
  //       if(str[j] == 'A' && str[j+1] == 'B'){
  //         cout << "YES" << endl;
  //         return 0;
  //       }
  //     }
  //   }
  // }

  // cout << "NO" << endl;

  return 0;
}