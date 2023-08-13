#include <bits/stdc++.h>

using namespace std;

int n, m, k, a, b;
vector <vector <int>> adj;
vector <bool> isShop;
vector <int> distances;

void bfs(int cur){
  list <int> qu;
  list <int> dist;
  vector <bool> visited;
  for(int i = 0; i <= n; i++)visited.push_back(false);
  qu.push_back(cur);
  dist.push_back(0);
  int numFound = 0;
  while(numFound < k){
    int curNode = qu.front();
    qu.pop_front();
    int curDist = dist.front();
    dist.pop_front();
    if(visited[curNode] == true)continue;
    visited[curNode] = true;
    if(isShop[curNode] == true){
      distances[curNode] += curDist;
      numFound++;
    }
    //go to all neighbours
    for(int i = 0; i < adj[curNode].size(); i++){
      qu.push_back(adj[curNode][i]);
      dist.push_back(curDist + 1);
    }
  }
  return;
}

int main() {
  cin >> n >> m >> k >> a >> b;
  vector <int> tmp;
  for(int i = 0; i <= n; i++){
    adj.push_back(tmp);
    isShop.push_back(false);
    distances.push_back(0);
  }
  for(int i = 0; i < k; i++){
    int d;
    cin >> d;
    isShop[d] = true;
  }
  for(int i = 0; i < m; i++){
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  //bfs from A to all k shops, and update distances
  bfs(a);
  bfs(b);
  int best = INT_MAX;
  for(int i = 1; i <= n; i++){
    if(isShop[i] && distances[i] < best)best = distances[i];
  }
  cout << best << endl;
}