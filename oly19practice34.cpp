#include <bits/stdc++.h>

using namespace std;

int n, m, t;
unsigned short adj[1001][1001];
int dist[1001], distBack[1001];

void dijkstra(int src){
  priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> pq;
  memset(dist, 9999, sizeof(dist));
  memset(distBack, 9999, sizeof(distBack));
  pq.push(make_pair(0, src));
  dist[src] = 0;
  while(!pq.empty()){
    int u = pq.top().second;
    pq.pop();
    //update distances and add to queue
    for(int i = 0; i < n; i++){
      int v = i;
      int weight = adj[u][i];
      if(dist[v] > weight + dist[u]){
        dist[v] = weight + dist[u];
        pq.push(make_pair(dist[v], v));
      }
    }
  }
  pq.push(make_pair(0, src));
  distBack[src] = 0;
  while(!pq.empty()){
    int u = pq.top().second;
    pq.pop();
    //update distances and add to queue
    for(int i = 0; i < n; i++){
      int v = i;
      int weight = adj[i][u];
      if(distBack[v] > weight + distBack[u]){
        distBack[v] = weight + distBack[u];
        pq.push(make_pair(distBack[v], v));
      }
    }
  }
  return;
}

int main() {
  memset(adj, USHRT_MAX, sizeof(adj));
  cin >> n >> m >> t;
  for(int i = 0; i < m; i++){
    unsigned short a, b, c;
    cin >> a >> b >> c;
    adj[a - 1][b - 1] = min(adj[a - 1][b - 1], c);
  }
  dijkstra(t - 1);
  int maxAns = 0;
  for(int i = 0; i < n; i++){
    maxAns = max(maxAns, dist[i] + distBack[i]);
  }
  cout << maxAns << endl;
}