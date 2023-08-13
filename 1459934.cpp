#include <bits/stdc++.h>

using namespace std;

struct edge{
  int b, t, h;
  edge(int x, int y, int z){
    b = x;
    t = y;
    h = z;
  }
};

int K, N, M, A, B;
vector <edge> graph[2002];
bool inqu[2002] = {0};
int dist[2002][202];//stores the min distance to the node, with amount of damage as the second parameter

int main() {
  cin >> K >> N >> M;
  for(int i = 0; i < M; i++){
    int a, b, t, h;
    cin >> a >> b >> t >> h;
    graph[a].push_back(edge(b, t, h));
    graph[b].push_back(edge(a, t, h));
  }
  cin >> A >> B;
  //create priority qu 
  priority_queue <int, vector <int>, greater<int>> qu;
  memset(dist, 0x3f, sizeof(dist));
  dist[A][0] = 0;
  inqu[A] = true;
  qu.push(A);
  while(!qu.empty()){
    int curNode = qu.top();
    inqu[curNode] = false;
    qu.pop();
    for(int i = 0; i < graph[curNode].size(); i++){
      for(int j = 0; j + graph[curNode][i].h < K; j++){
        int dest = graph[curNode][i].b, time = graph[curNode][i].t, dmg = graph[curNode][i].h;
        int newTime = dist[curNode][j] + time;
        if(newTime < dist[dest][j + dmg]){
          dist[dest][j + dmg] = newTime;
          if(!inqu[dest]){
            qu.push(dest);
            inqu[dest] = true;
          }
        }
      }
    }
  }
  int best = 0x3f3f3f3f;
  for(int i = 0; i < K; i++){
    if(dist[B][i] < best)best = dist[B][i];
  }
  if(best >= 0x3f3f3f3f)cout << -1 << endl;
  else cout << best << endl;
}