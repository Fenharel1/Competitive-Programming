#include <bits/stdc++.h>
#define REP(q,n) for(q=0; q < n; q++)
using namespace std;

int main(){
  int n;
  while(cin >> n, n){
    cin.ignore();
    int right[n+5], left[n+5];
    int mindis = 50;
    int contx = 0;
    for(int i = 0; i < n+5; i++) right[i]=left[i]=0;
    for(int i = 0; i < n; i++){
      char str[30];
      cin.getline(str,26);
      for(int j = 0; j < 24; j++){
        if(str[j] == 'X') contx++;
        if(str[j]=='X' && str[j+1]==' '){
          left[i] = j;
        }
        if(str[j]==' ' && str[j+1] == 'X'){
          right[i] = j+1;
        }
      }
      mindis = min(mindis, right[i] - left[i] - 1);
    }
    int cont = 0;
    for(int i = 0; i < n; i++){
      int blanks = right[i] - left[i] - 1;
      if(blanks > 0 && blanks >= mindis) cont+=blanks-(mindis > 0 ? mindis : 0);
    }
    cout << cont << endl;
    
  }
  return 0;
}