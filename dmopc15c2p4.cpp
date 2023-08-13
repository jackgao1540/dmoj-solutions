#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MM = 1e5 + 5;

struct E{
  ll s, f, val;
}a[MM];

int N; ll dp[MM];

bool cmp(E x, E y){return x.f < y.f;}

bool cmp2(ll start, E x){
  return start <= x.f;
}

int main() {
   scanf("%d", &N);
   for(int i = 1; i <= N; i++){
     scanf("%lld %lld %lld", &a[i].s, &a[i].f, &a[i].val);
     a[i].f += a[i].s - 1;
   }
   sort(a + 1, a + N + 1, cmp);
   for(int i = 1; i <= N; i++){
     int onest = upper_bound(a, a + i, a[i].s, cmp2) - a - 1;
     dp[i] = max(dp[i - 1], dp[onest] + a[i].val);
   }
   printf("%lld\n", dp[N]);
}