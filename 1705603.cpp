#include <bits/stdc++.h>

using namespace std;

int N, bit[32005] = {0}, lvl[32001] = {0}; 

void update(int pos, int val){
  for(int i = pos; i < 32005; i+=i&-i){
    bit[i] += val;
  }
}

int query(int pos){
  int ret = 0;
  for(int i = pos; i > 0; i-=i&-i)ret += bit[i];
  return ret;
}

int main() {
  scanf("%d", &N);
  for(int i = 1, x, y; i <= N; i++){
    cin >> x >> y;
    x++;
    lvl[query(x)]++;
    update(x, 1);
  }
  for(int i = 0; i < N; i++)cout << lvl[i] << endl;
}