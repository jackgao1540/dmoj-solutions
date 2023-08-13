#include <bits/stdc++.h>

using namespace std;

int n, m, s1[102], p1[102], s2[102], p2[102], ans, x[102], y[102];

bool check(int k){
  int totcost = 0;
  for(int i = 0; i < n; i++){
    int need = max(0, k * x[i] - y[i]), cost = 1e9;
    for(int j = 0; j*p1[i] <= m; j++){
      int q = 0;
      if(j * s1[i] < need)q = (need - j*s1[i] + s2[i] - 1)/s2[i];
      cost = min(cost, j*p1[i] + q * p2[i]);
    }
    totcost += cost;
  }
  return totcost <= m;
}

int main() {
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    cin >> x[i] >> y[i] >> s1[i] >> p1[i] >> s2[i] >> p2[i];
  }
  int lo = 0, hi = 100000;
  while(lo <= hi){
    int mid = (lo + hi)/2;
    //cout << mid <<endl;
    if(check(mid)){
      ans = mid;
      lo = mid + 1;
    }else hi = mid - 1;
  }
  cout << ans << endl;
}