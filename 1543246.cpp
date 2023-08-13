#include <bits/stdc++.h>

//create directed graph and use topological sort

using namespace std;

const int mm = 102;
int n, indeg[26], ans[26], tot = 0, cnt = 0; vector <int> adj[26]; string a[102], b[102];
bool vis[26];

int main() {
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> b[i];
  }
  for(int x, i = 1; i <= n; i++){
    cin >> x;
    a[i] = b[x];
  }
  //a is sorted, b is not
  //create the directed graph
  for(int i = 1; i < n; i++){
    int j = i + 1;
    bool flag = false;
    for(int k = 0; k < min(a[i].size(), a[j].size()); k++){
      if(a[i][k] != a[j][k]){
        flag = true;
        int u = a[i][k] - 'a', v = a[j][k] - 'a';
        adj[u].push_back(v);
        if(!vis[u])cnt++;
        if(!vis[v])cnt++;
        vis[u] = vis[v] = true;
        indeg[v]++;
        break;
      }
    }
    if(!flag && a[i].size() > a[j].size()){cout << "NE" << endl; return 0;}
  }
  queue <int> q;
  for(int i = 0; i < 26; i++){
    if(vis[i] && indeg[i] == 0)q.push(i);
  }
  while(!q.empty()){
    int u = q.front(); q.pop(); ans[u] = ++tot;
    for(int v: adj[u]){
      indeg[v]--;
      if(indeg[v] == 0)q.push(v);
    }
  }
  if(tot != cnt) {cout << "NE" <<endl;return 0;}
  cout << "DA" <<endl;
  for(int i = 0; i < 26; i++){
    if(ans[i] > 0)cout << (char)(ans[i] + 'a' - 1);
    else{
      ++tot; cout << (char)(tot + 'a' - 1);
    }
  }
  cout << endl;
}