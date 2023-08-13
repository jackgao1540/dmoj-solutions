#include <bits/stdc++.h>

using namespace std;

const int MM = 1.5e5 + 5;
int N, psa[MM], bit[2*MM];
long long ans;

void update(int pos, int val){
  for(int i = pos + MM; i < 2 *MM; i+=i&-i){
    bit[i] += val;
  }
}

int query(int pos){
  int ret = 0;
  for(int i = pos + MM; i > 0; i -=i&-i){
    ret += bit[i];
  }
  return ret;
}

int main() {
  cin >> N; update(0, 1);
  for(int i = 1; i <= N; i++){
    int x;
    cin >> x;
    if(x == 1)psa[i] = psa[i - 1] + 1;
    else psa[i] = psa[i - 1] - 1;
    ans += query(psa[i] - 1);
    update(psa[i], 1);
  }
  cout << ans;
}