#include <bits/stdc++.h>

using namespace std;

int n, m;
unsigned short adj[1001][1001];

vector <int> dijkstra(int src){
  priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> pq;
  vector <int> dist(n, INT_MAX);
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
  return dist;
}

int main() {
  memset(adj, USHRT_MAX, sizeof(adj));
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    unsigned short a, b, c;
    cin >> a >> b >> c;
    adj[a - 1][b - 1] = min(adj[a - 1][b - 1], c);
    adj[b - 1][a - 1] = min(adj[b - 1][a - 1], c);
  }
  vector <int> dist = dijkstra(0);
  for(int i = 0; i < n; i++)cout << (dist[i] == USHRT_MAX ? -1 : dist[i]) << endl;
}