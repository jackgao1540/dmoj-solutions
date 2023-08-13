#include <bits/stdc++.h>

using namespace std;

const int MM = 1e5 + 10;
int N, M, In[MM], mod = 1e9 + 7;
vector <int> adj[MM];
list <int> Q; 
long long cnt[MM], dp[MM], ans;

int main(){
  cin >> N >> M;
  for(int i = 1, u, v; i <= M; i++){
    cin >> u >> v;
    adj[u].push_back(v);
    In[v]++;
  }
  for(int i = 1; i <= N; i++){
    if(In[i] == 0){
      Q.push_back(i);
      cnt[i] = 1;
      dp[i] = 0;
    }
  }
  while(!Q.empty()){
    int u = Q.front();
    Q.pop_front();
    for(int v: adj[u]){
      cnt[v] = (cnt[v] + cnt[u])%mod;
      dp[v] = (dp[v] + dp[u] + cnt[u])%mod;
      In[v]--;
      if(In[v] == 0){
        Q.push_back(v);
      }
    }
  }
  for(int i = 1; i <= N; i++){
    if(adj[i].empty())ans = (ans + dp[i]) % mod;
  }
  cout << ans << endl;
}