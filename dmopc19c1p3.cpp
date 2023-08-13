#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pi;

const int MM = 3e5+5, mod = 1e9 + 7;
int n, m, k, lo, hi;
vector <pi> adj[MM];
pi val[MM]; bool vis[MM], vis2[MM];
long long ans = 1;

void dfs(int u){
  vis[u] = 1; 
  for(pi e: adj[u]){
    int v = e.first, w = e.second;
    if(!vis[v]){
      val[v] = {-val[u].first, w - val[u].second};
      dfs(v);
    }
  }
}

void dfs2(int u){
  vis2[u] = 1;
  if(val[u].first > 0){
    lo = max(lo, 1 - val[u].second);
    hi = min(hi, k - val[u].second);
  }
  else{
    lo = max(lo, val[u].second - k);
    hi = min(hi, val[u].second - 1);
  }
  for(pi e: adj[u]){
    int v = e.first, w = e.second; pi tmp = {-val[u].first, w - val[u].second};
    if(val[v] == tmp)continue;
    if(val[v].first == tmp.first || (val[v].second - tmp.second)%(tmp.first - val[v].first) != 0){
      printf("0\n");
      exit(0);
    }
    int sol = (val[v].second - tmp.second)/(tmp.first - val[v].first);
    lo = max(lo, sol);
    hi = min(hi, sol);
  }
  for(pi e: adj[u]){
    if(!vis2[e.first])dfs2(e.first);
  }
}

int main(){
  scanf("%d%d%d", &n, &m, &k);
  for(int i = 1; i <= m; i++){
    int u, v, z;
    scanf("%d%d%d", &u, &v, &z);
    adj[u].push_back({v, z});
    adj[v].push_back({u, z});
  }
  for(int i = 1; i <= n; i++){
    if(!vis[i]){
      val[i] = {1, 0};
      dfs(i);
      lo = 1, hi = k;
      dfs2(i);
      if(lo > hi){
        printf("0\n");
        exit(0);
      }
      //cout << lo << ' ' << hi << endl;
      ans = (ans *(hi - lo + 1)) % mod;
    }
  }
  cout << ans << endl;
}
/*#include <bits/stdc++.h>

using namespace std;

int n, m, k, lo, hi;
vector <pair <int, int>> adj[300001];

void bfs(int cur){
  list <int> qu;
  list <pair <int, int>> newVals;
  vector <pair <int, int>> vals;
  for(int i = 0; i <= n; i++){
    vals.push_back({0, 0});
  }
  vals[cur] = {1, 0};
  newVals.push_back({1, 0});
  qu.push_back(cur);
  while(!qu.empty()){
    int c = qu.front();
    qu.pop_front();
    pair <int, int> newVal = newVals.front();
    if((vals[c].first != 0 && vals[c].second != 0) && (vals[c].first != newVal.first && vals[c].second != newVal.second)){
      //conflicting solutions
      lo = 1;
      hi = 0;
      return;
    }
    for(int i = 0; i < adj[c].size(); i++){
      qu.push_back(adj[c][i].first);

    }
  }
}

int main() {
  scanf("%d%d%d", &n, &m, &k);
  for(int i  = 0; i < m; i++){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    adj[a].push_back(c);
    adj[b].push_back(a);
  }
  int ans = 1;
  for(int i = 1; i <= n; i++){
    lo = 1, hi  = k;
    bfs(i);
    ans *= max(0, hi - lo + 1);
  }
  printf("%d\n", ans);
}*/