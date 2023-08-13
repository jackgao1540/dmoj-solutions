#include <bits/stdc++.h>

using namespace std;

#define ll long long

int N, Q;
ll adj[102][102], dp[102][102][102];

ll fun(int s, int t, int d){
  if(dp[s][t][d] != -1)return dp[s][t][d];
  if(s == t)return dp[s][t][d] = 0;
  if(d == 1)return adj[s][t];
  ll ret = 1e18;
  for(int u = 1; u <= N; u++){
    ret = min(ret, max(adj[s][u], fun(u, t, d- 1)));
  }
  return dp[s][t][d] = ret;
}

int main() {
  memset(adj, 0x3f, sizeof(adj));
  memset(dp, -1, sizeof(dp));
  scanf("%d", &N);
  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= N; j++){
      int x;
      scanf("%d", &x);
      if(x != 0)adj[i][j] = x;
    }
    adj[i][i] = 0;
  }
  //floyd warshall
  for(int k = 1; k <= N; k++){
    for(int i = 1; i <= N; i++){
      for(int j = 1; j <= N; j++){
        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
      }
    }
  }
  scanf("%d", &Q);
  for(int i = 1, s, t, d; i <= Q; i++){
    scanf("%d %d %d", &s, &t, &d);
    if(adj[s][t] > 1e12)printf("0\n");
    else printf("%lld\n", fun(s, t, d));
  }
}