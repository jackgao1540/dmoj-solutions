#include <bits/stdc++.h>

using namespace std;

int sTeam=0, bTeam=0;
vector <pair <int, int>> adj[500005];
bool alive[500005] = {0};
bool Team[500005] = {0};
bool visited[500005] = {0};

void dfs(int node, bool team){
  //setting the teams
  if(visited[node])return;
  else visited[node] = true;
  if(team == false){
    sTeam++;
    Team[node] = team;
  }else {
    bTeam++;
    Team[node] = team;
  }
  for(int i = 0; i < adj[node].size(); i++){
    dfs(adj[node][i].first, !team);
  }
}

void setAlive(int node, int al){
  if(al == 0)alive[node] = false;
  //if(!al)cout << "node " << node << " died" << endl;
  if(visited[node])return;
  else visited[node] = true;
  for(int i = 0; i < adj[node].size(); i++){
    setAlive(adj[node][i].first, adj[node][i].second);
  }
}

int main() {
    int n, r;
    scanf("%d%d", &n, &r);
    r--;
    
    for(int i = 0; i < n; i++){
      int d;
      scanf("%d", &d);
      for(int j = 0; j < d; j++){
        int x;
        scanf("%d", &x);
        adj[i].push_back(make_pair(x - 1, 0));
        adj[x - 1].push_back(make_pair(i, 1));
      }
    }
    dfs(r, 0);
    //set alive and not alive
    memset(alive, true, sizeof(alive));
    memset(visited, false, sizeof(visited));
    setAlive(r, true);
    int s = 0, b = 0;
    for(int i = 0; i < n; i++){
      if(Team[i] == 0){
        s += alive[i];
      }else b += alive[i];
    }
    cout << s << ' ' << b << endl;
    return 0;
}