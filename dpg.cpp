#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct node{
  vector <int> outDegs;
  vector <int> inDegs;
};

int max(int a, int b){
  return a > b ? a : b;
}

int n, m;
vector <node> graph;
vector <int> zeroIndegs;
vector <int> longest;

int topSort(int cur){
  if(longest[cur] != 0)return longest[cur];
  if(graph[cur].outDegs.size() == 0){
    longest[cur] = 0;
    return 1;
  }
  int d = 0;
  for(int i = 0; i < graph[cur].outDegs.size(); i++){
    int x = topSort(graph[cur].outDegs[i]);
    d = max(d, x);
  }
  longest[cur] = d + 1;
  return d + 1;
}

int main() {
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    node tmp;
    graph.push_back(tmp);
    zeroIndegs.push_back(1);
    longest.push_back(0);
  }
  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    graph[a - 1].outDegs.push_back(b - 1);
    graph[b - 1].inDegs.push_back(a - 1);
    zeroIndegs[b - 1] = 0;
  }
  int l = 0;
  for(int i = 0; i < n; i++){
    if(zeroIndegs[i]){
      int d= topSort(i);
      l = max(d, l);
    }
  }
  cout << l - 1;
}