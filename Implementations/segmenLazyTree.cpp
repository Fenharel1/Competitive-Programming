#include <bits/stdc++.h>
#define MAX 1000
using namespace std;

int input[MAX], tree[MAX*3], lazy[MAX*3];

void build(int node, int start, int end){
  if(start > end) return;
  if(start == end) {
    tree[node] = input[start];
    return;
  }
  int mid = (start + end) / 2;
  build(node * 2, start, mid);
  build(node * 2 + 1, mid + 1, end);
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void updateChildren(int node, int start, int end, int op){
  tree[node] += op;
  lazy[node * 2] += op;
  lazy[node * 2 + 1] += op;
}

void update(int node, int start, int end, int l, int r, int value){
  if(start > end) return;
  if(lazy[node] != -1){
    updateChildren(node, start, end, lazy[node]);
    lazy[node] = -1;
  }

  if(l > end || r < start) return;

  if(l <= start && r >= end){
    updateChildren(node, start, end, value);
    return;
  }

  int mid = (start + end) / 2;
  update(node * 2, start, mid, l, r, value);
  update(node * 2 + 1, mid + 1, end, l, r, value);
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int queryRange(int node, int start, int end, int l, int r){
  if(start > end) return 0;
  if(lazy[node] == -1){
    updateChildren(node, start, end, lazy[node]);
    lazy[node] = -1;
  }

  if(l > end || r < start) return 0;
  
  if(start >= l && end <= r) return tree[node];

  int mid = (start + end) / 2;
  int op1 = queryRange(node * 2, start, mid, l, r);
  int op2 = queryRange(node * 2 + 1, mid + 1, end, l, r);
  return op1 + op2;
}

int main(){;
  ios::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  return 0;
}