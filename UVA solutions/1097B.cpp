#include <bits/stdc++.h>
using namespace std;

int arr[20];
int n;


int sol(int idx, int sum){
  if(idx == n && sum == 0) return 1;
  if(idx == n && sum != 0) return 0;
  int op1 = sol(idx+1, (sum + arr[idx])%360); 
  int op2 = sol(idx+1, (sum - arr[idx])%360);
  return op1 + op2; 
}

int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }

  int solution = sol(0,0);
  if(solution > 0) cout << "YES" << endl;
  else cout << "NO" << endl;

  return 0;
}