#include <bits/stdc++.h>

using namespace std;

int n;
vector <pair <int, int>> input;
vector <vector <int>> adj;
vector <bool> states;

void bfs(int node){
  vector <bool> visited = states;
  list <int> qu;
  list <int> State;
  State.push_back(true);
  qu.push_back(node);
  while(!qu.empty()){
    int cur = qu.front();
    qu.pop_front();
    int curState = State.front();
    State.pop_front();
    if(visited[cur])continue;
    else visited[cur] = true;
    states[cur] = curState;
    //go to all neighbours
    for(int i = 0; i < adj[cur].size(); i++){
      qu.push_back(adj[cur][i]);
      State.push_back(!curState);
    }
  }
  return;
}

int main() {
    cin >> n;
    vector <int> tmp;
    for(int i = 0; i <= n; i++){
      adj.push_back(tmp);
      states.push_back(false);
    }
    for(int i = 0; i < n - 1; i++){
      int a, b;
      cin >> a >> b;
      input.push_back(make_pair(a, b));
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    bfs(1);
    //for(int i = 1; i <= n; i++)cout << states[i] << endl;
    for(int i = 0; i < n - 1; i++){
      int a = input[i].first, b = input[i].second;
      cout << !states[a] << endl;
    }
    return 0; 
}