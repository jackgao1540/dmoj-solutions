#include <bits/stdc++.h>

using namespace std;

int n, m; double dp[1000002]; vector <int> adj[1000002];

int main(){
  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; i++){
    int x, y;
    scanf("%d %d", &x, &y);
    adj[x].push_back(y);
  }
  dp[1] = 1.0;
  for(int i = 1; i <= n; i++){
    if(adj[i].size() > 0){
      double p = dp[i] / adj[i].size();
      for(int v: adj[i])dp[v] += p;
    }else{
      printf("%.9f\n", dp[i]);
    }
  }
}