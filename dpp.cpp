#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 100002;
int N, mod=1e9+7; vector<int> adj[MM]; ll dp[MM][2];
void dfs(int u, int pa){
    dp[u][0] = 1; dp[u][1] = 1;
    for(int v: adj[u]){
        if(v == pa) continue;
        dfs(v, u); dp[u][0] = (dp[u][0] * dp[v][1])%mod; dp[u][1] = (dp[u][1] * (dp[v][0] + dp[v][1]))%mod;
    }
}
int main(){
    scanf("%d", &N);
    for(int i=1, u, v; i<N; i++){
        scanf("%d %d", &u, &v); adj[u].push_back(v); adj[v].push_back(u);
    }
    dfs(1, 0);  printf("%lld\n", (dp[1][0] + dp[1][1])%mod);
}