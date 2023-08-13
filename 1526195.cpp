#include <bits/stdc++.h>
//uniting the water empire
using namespace std;

const int mm = 5e5 + 5;
int n, h[mm], cnt[mm], top = -1;
long long ans = 0;

int main() {
  scanf("%d", &n);
  for(int i = 1, x; i <= n; i++){
    scanf("%d", &x);
    while(top >= 0 && h[top] < x){
      ans += cnt[top];
      top--;
    }
    if(top < 0){
      top++;
      h[top] = x;
      cnt[top] = 1;
    }else{
      if(h[top] == x){
        ans += cnt[top];
        if(top >= 1)ans++;
        cnt[top]++;
      }else{
        ans++;
        top++;
        h[top] = x;
        cnt[top] = 1;
      }
    }
  }
  printf("%lld", ans);
}