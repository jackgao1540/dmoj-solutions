#include <bits/stdc++.h>

using namespace std;

struct node{
  vector <int> connections;
};

node graph[1000];
int distances[1000][1000];

void bfs(int cur){
  int searched[1000] = {0};
  list <int> qu;
  qu.push_back(cur);
  list <int> dists;
  dists.push_back(0);
  while(!qu.empty()){
    int t = qu.front();
    int d = dists.front();
    qu.pop_front();
    dists.pop_front();
    if(searched[t])continue;
    searched[t] = 1;
    distances[cur][t] = d;
    for(int i = 0; i < graph[t].connections.size(); i++){
      qu.push_back(graph[t].connections[i]);
      dists.push_back(d + 1);
    }
  }
  return;
}

int main() {
  int n, m, t;
  cin >> n >> m >> t;
  for(int i = 0; i < n; i++)for(int j = 0; j < n; j++)distances[i][j] = -1;
  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    graph[a - 1].connections.push_back(b - 1);
  }
  for(int i = 0; i < n; i++){
    bfs(i);
  }
  int q;
  cin >> q;
  for(int i = 0; i < q; i++){
    int a, b;
    cin >> a >> b;
    if(distances[a- 1][b - 1] != -1)cout << t*distances[a - 1][b - 1] << endl;
    else cout << "Not enough hallways!" << endl;
  }
}