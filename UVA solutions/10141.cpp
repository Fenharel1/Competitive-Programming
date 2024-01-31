#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, p, count = 1;
  while(scanf("%d %d", &n, &p), (n || p)){
    if(count != 1) cout << endl;
    char str[85];
    cin.ignore();
    for (int i = 0; i < n; i++){
      cin.getline(str, 85, '\n');
    }
    char ans[85]; 
    float minPrice = -1;
    int maxcomp = -1;
    for(int q = 0; q < p; q++){
      char aux[85];
      cin.getline(aux, 85, '\n');
      float price;
      int m; 
      cin >> price >> m;
      if(m > maxcomp || (m == maxcomp && price < minPrice) ){
        strcpy(ans, aux);
        maxcomp = m;
        minPrice = price;
      }

      cin.ignore();
      while(m--){
        char aux2[85];
        cin.getline(aux2, 85, '\n');
      }
    }
    cout << "RFP #" << count++ << endl;
    cout << ans << endl;
  }
  return 0;
}