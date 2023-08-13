#include <bits/stdc++.h>
//use BIT to check number of numbers before it that were smaller, than update the current ranking to 1
using namespace std;
typedef pair <int, int> pi;
const int MM = 100002;
int n, a[MM], rk[MM], bit[MM];
pi p[MM];
long long ans = 0;

bool cmp(pi x, pi y){return x.first > y.first || (x.first == y.first && x.second > y.second);}

int query(int pos){
  int sum = 0;
  for(int i = pos; i > 0; i-=i&-i){
    sum += bit[i];
  }
  return sum;
}

void update(int pos, int val){
  for(int i = pos; i <= n; i+=i&-i){
    bit[i] += val;
  }
}

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; i++){
    scanf("%d", &a[i]);
    p[i] = make_pair(a[i], i);
  }
  sort(p + 1, p + 1 + n, cmp);
  for(int i = 1; i <= n; i++){
    rk[p[i].second] = i;
  }
  for(int i=  1; i <= n; i++){
    ans += query(rk[i]) + 1;
    update(rk[i], 1);
  }
  printf("%.2f\n", (double)ans/n);
}