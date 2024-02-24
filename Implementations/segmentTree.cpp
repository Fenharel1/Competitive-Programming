#include <bits/stdc++.h>
#define MAX 1000
#define REP(n) for(int i = 0; i < n; i++)
using namespace std;

int n;
int input[MAX], tree[MAX*2];

void build(int node, int start, int end){
  if(start == end){
    tree[node] = input[end];
    return;
  }
  int mid = (start + end) / 2;
  build(node * 2, start, mid);
  build(node * 2 + 1, mid + 1, end);
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void query(int node, int start, int end, int l, int r){
  
}

int main(){
  cout << "ingrese n" <<endl;
  cin >> n;
  REP(n){
    cin >> input[i];
  }
  cout <<"ingresado:" << endl;
  REP(n){
    cout << input[i] << " ";
  }
  cout << endl;

  build(1, 0, n-1);
  REP(n*2){
    cout << tree[i] << " ";
  }
  cout << endl;
  return 0;
}
/*
1
2       3
4  5    6    7
89 1011 1213 1415
01  2 3  4 5 6 7*/