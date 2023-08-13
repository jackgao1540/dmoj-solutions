#include <bits/stdc++.h>

using namespace std;

int n, m;
vector <vector <pair <int, int>>> adj;

struct edge{
  int src, dest, wt;
  edge(int a, int b, int c){
    src = a;
    dest = b;
    wt = c;
  }
};

vector <int> dijkstra(int src){
  priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> pq;
  vector <int> dist(n, INT_MAX);
  pq.push(make_pair(0, src));
  dist[src] = 0;
  while(!pq.empty()){
    int u = pq.top().second;
    pq.pop();
    //update distances and add to queue
    for(int i = 0; i < adj[u].size(); i++){
      int v = adj[u][i].first, weight = adj[u][i].second;
      if(dist[v] > dist[u] + weight){
        dist[v] = dist[u] + weight;
        pq.push(make_pair(dist[v], v));
      }
    }
  }
  return dist;
}

int main() {
  cin >> n >> m;
  vector <pair <int, int>> tmp;
  vector <edge> edges;
  for(int i = 0; i < n; i++)adj.push_back(tmp);
  for(int i = 0; i < m; i++){
    unsigned short a, b, c;
    cin >> a >> b >> c;
    adj[a - 1].push_back(make_pair(b - 1, c));
    adj[b - 1].push_back(make_pair(a - 1, c));
    edges.push_back(edge(a - 1, b - 1, c));
  }
  vector <int> dist1 = dijkstra(0), dist2 = dijkstra(n - 1);
  int shortestDist = dist1[n - 1], ans = INT_MAX;
  for(edge e : edges){
    int nd = dist1[e.src] + dist2[e.dest] + e.wt;
    if(nd < ans && nd > shortestDist){
      ans = nd;
    }
    nd = dist1[e.dest] + dist2[e.src] + e.wt;
    if(nd < ans && nd > shortestDist){
      ans = nd;
    }
  }
  cout << ans << endl;
}