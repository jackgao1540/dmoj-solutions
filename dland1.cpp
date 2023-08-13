#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  vector <int> points;
  vector <long> diff;
  for(int i = 0; i < n; i++){
    int x;
    scanf("%d", &x);
    points.push_back(x);
    diff.push_back(0);
  }
  for(int i = 0; i < q; i++){
    int a, b;
    scanf("%d%d", &a, &b);
    a--; b--;
    diff[a] += 1;
    if(b < n - 1)diff[b + 1] -= 1;
  }
  for(int i = 1; i < n; i++){
    diff[i] += diff[i - 1];
  }
  //for(int i : diff)cout << i << ' ';
  //cout << endl;
  sort(diff.begin(), diff.end());
  sort(points.begin(), points.end());
  long ans =0 ;
  for(int i = 0; i < n; i++){
    ans += diff[i] * points[n -i - 1];
  }
  cout << ans << endl;
}