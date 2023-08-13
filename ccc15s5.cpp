#include <bits/stdc++.h>

using namespace std;

int n, m, oPies[3005], nPies[105], dp[3005][2][105][105];

int func(int node, int t, int l, int r){
  int& arr = dp[node][t][l][r];
  if(arr != -1)
    return arr;
  if(node == n + 1){
    if(l <= r){
      if(t)return arr=nPies[r] + func(node, 0, l, r-1);
      return arr = func(node, 1, l + 1, r);
    }
    return arr = 0;
  }
  if(t){
      arr = max(func(node, 0, l, r), oPies[node] + func(node + 1, 0, l, r));
        if(l <= r)
            arr = max(arr, nPies[r] + func(node, 0, l, r - 1));
    }
    else{
        arr = func(node + 1, 1, l, r);
        if(l <= r)arr = max(arr, func(node, 1, l + 1, r));
    }
    return arr;
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &oPies[i]);
    scanf("%d", &m);
    for(int i = 1; i <= m; i++)
        scanf("%d", &nPies[i]);
    sort(&nPies[1], &nPies[m + 1]);
    memset(dp, -1, sizeof dp);
    printf("%d\n", func(1, 1, 1, m));
    return 0;
}