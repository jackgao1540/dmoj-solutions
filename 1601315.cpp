#include <bits/stdc++.h>

using namespace std;

/*int n, bit[2003][2003];

int main() {
  cin >> n;
  long ans = 0;
  for(int i = 0; i < n; i++){
    int c;
    cin >> c;
    if(c == 1){
      int r, c, t;
    }else{
      int r, c, x;
    }
  }
}*/
const int mm = 2003;
int n, op, r, c, t, bit[mm][mm], mod = 1e9 + 7; 
long long ans = 0;

void upd(int k, int pos, int val){
  for(int i = pos; i < mm; i +=i&-i){
    bit[k][i] += val;
  }
}

int sum(int k, int pos){
  int ret = 0;
  for(int i = pos; i > 0; i -= i & -i){
    ret += bit[k][i];
  }
  return ret;
}

int main(){
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d%d%d%d", &op, &r, &c, &t);
    if(op == 1){
      upd(r + c, r, t);
    }else{
      ans += (sum(r + c, r) - sum(r + c, r-t-1) + mod) % mod;
      ans %= mod;
    }
  }
  cout << ans << endl;
}