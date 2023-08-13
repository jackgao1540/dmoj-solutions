#include <iostream>
#include <vector>

using namespace std;

struct node{
  vector <int> connections;
};

vector <node> points;
vector <int> dp;
int n;

int numWays(int cr){
  if(cr == n - 1){
    dp[cr] = 1;
    return 1;
  }
  node cur = points[cr];
  int total = 0;
  for(int i = 0; i < cur.connections.size(); i++){
    if(dp[cur.connections[i]] == -1){
      total += numWays(cur.connections[i]);
    }else total += dp[cur.connections[i]];
  }
  dp[cr] = total;
  return total;
}

int main() {
  cin >> n;
  node tmp;
  for(int i = 0; i < n; i++){
    points.push_back(tmp);
    dp.push_back(-1);
  }
  int a, b;
  cin >> a >> b;
  while(a != 0){
    points[a - 1].connections.push_back(b - 1);
    cin >> a >> b;
  }
  cout << numWays(0) << endl;
  /*for(int i = 0; i < n; i++){
    cout << dp[i] << endl;
  }*/
}