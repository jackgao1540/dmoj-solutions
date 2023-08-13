#include <bits/stdc++.h>

using namespace std;

#define MM 210
#define MOD 1000000007
#define pib pair <int, bool>
int N, W, M;
long long dp[MM][MM][2];
vector <pib> adj[MM];
bool r[MM];

void recur(int c){
  dp[c][0][0] = dp[c][1][1] = 1; 
  for (int n = 0; n < adj[c].size(); n++){
    int next = adj[c][n].first;
    bool b = adj[c][n].second;
    recur(next);
    for (int j = W; j >=0; j--) {
      long long w = 0, _w = 0;
      for (int k = 0; k <= j; k++){
        _w += dp[c][j-k][0] * (dp[next][k][0] + dp[next][k][1]);
        _w %= MOD;
        if (b)
          w += dp[c][j-k][1] * dp[next][k][0];
        else
          w += dp[c][j-k][1] * dp[next][k][1];
        w %= MOD;
      }
      dp[c][j][0] = _w;
      dp[c][j][1] = w;
    }
  }
}

int main() {
  scanf("%d%d%d", &N, &W, &M);
  for(int i = 0; i < M; i++){
    int x, y; char c;
    scanf(" %c%d%d", &c, &x, &y);
    adj[x].push_back(make_pair(y, (c == 'A' ? true : false)));
    r[y] = true;
  }
  for(int i = 1; i <= N; i++){
    if(!r[i]){
      adj[0].push_back(make_pair(i, false));
    }
  }
  recur(0);
  printf("%lld\n", dp[0][W][0]);
}