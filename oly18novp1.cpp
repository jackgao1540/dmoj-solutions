#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector <pair <int, int>> segments;
  for(int i = 0, x, y; i < n; i++){
    cin >> x >> y;
    segments.push_back(make_pair(y, x));
  }
  sort(segments.begin(), segments.end());
  n = 0;
  int ans = 0;
  for(int i = 0; i < segments.size(); i++){
    if(segments[i].second >= n){
      n = segments[i].first;
      ans++;
    }
  }
  cout << ans << endl;
}