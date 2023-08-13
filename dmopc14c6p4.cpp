#include <bits/stdc++.h>

using namespace std;

bool cmp(int a, int b){
  return a > b;
}

int main() {
  int n, m, h;
  vector <int> busTimes;
  //all differences must be <= h
  cin >> n >> m >> h;
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    busTimes.push_back(x);
  }
  unsigned int ans = 0;
  sort(busTimes.begin(), busTimes.end(), cmp);
  for(int i = 0; i < n - 1; i++){
    if(busTimes[i] - busTimes[i + 1] <= h)continue;
    double numBreaks = ((double)(busTimes[i] - busTimes[i + 1]) - (double)h)/((double)m);
    ans += ceil(numBreaks);
    busTimes[i + 1] += (int)(ceil(numBreaks)) * m;
  }
  cout << ans << endl;
}