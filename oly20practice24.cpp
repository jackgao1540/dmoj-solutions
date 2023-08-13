#include <bits/stdc++.h>

using namespace std;

int abs(int a){
  return a > 0 ? a : -a;
}

int main() {
  int t, n;
  cin >> t >> n;
  vector <pair <int, int>> stores (n);
  for(auto &it: stores)cin >> it.first;
  for(int i = 0; i < n; i++){
    if(stores[i].first < 0){
      stores[i].first = -stores[i].first;
      stores[i].second = -1;
    }
    else stores[i].second = 1;
  }
  sort(stores.begin(), stores.end());
  int pos = 0, ans = 0;
  for(int i = 0; i < n; i++){
    t -= abs(stores[i].first * stores[i].second - pos) ;
    pos = stores[i].first * stores[i].second;
    if(t >= 0){
      ans++;
    }else break;
  }
  cout << ans << endl;
}