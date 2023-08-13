#include <bits/stdc++.h>

using namespace std;

int n, m, adj[19][19] = {0}, dp[18][1 << 18];

int fun(int u, int mask){
  if(u == n - 1){
    return 0;
  }
  if(dp[u][mask] >= 0)return dp[u][mask];
  for(int v = 1; v < n; v++){
    if(adj[u][v] > 0 && ((mask & (1 << v)) == 0)){
      dp[u][mask] = max(dp[u][mask], adj[u][v] + fun(v, mask | (1 << v)));
    }
  }
  return dp[u][mask];
}

int main(){
  cin >> n >> m;
  memset(dp, -0x3f, sizeof(dp));
  for(int i = 0; i < m; i++){
    int a, b, c;
    cin >> a >> b >> c;
    adj[a][b] = c;
  }
  cout << fun(0, 1);
}