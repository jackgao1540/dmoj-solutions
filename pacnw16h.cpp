#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long l, n, tot = 0;
vector <pair <long, long>> segments;

int binarySearch(long ll){
  int l = -1, r = n - 1;
  while(l <= r){
    int mid = (l + r)/2;
    if(mid == -1)break;
    if(segments[mid].first < ll){
      l = mid + 1;
    }else{
      r = mid - 1;
    }
  }
  return l;
}

int main() {
  cin >> l >> n;
  for(int i = 0; i < n; i++){
    long x, y;
    cin >> x >> y;
    segments.push_back(make_pair(y, x));
  }
  sort(segments.begin(), segments.end());
  //do dp for the best answer
  long dp[200001] = {0};
  for(int i = 1; i <= n; i++){
    int key = binarySearch(segments[i - 1].second);
    if(key == -1){
      dp[i] = max(dp[i - 1], segments[i - 1].first - segments[i - 1].second + 1);
    }else dp[i] = max(dp[i - 1], segments[i - 1].first - segments[i - 1].second + 1 + dp[key]);
  }
  cout << l - dp[n] << endl;
}