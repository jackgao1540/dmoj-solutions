#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  long double shoes[10002] = {0}, psa[10002] = {0};
  long double dp[10002] = {0};
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> shoes[i + 1];
    psa[i + 1] = shoes[i + 1] + psa[i];
  }
  dp[1] = shoes[1];
  cout << fixed;
  cout << setprecision(1);
  for(int i = 2; i <= n; i++){
    if(i == 2){
      dp[i] = -min(shoes[1], shoes[2])/2 + psa[2];
      dp[i] = min(psa[2], dp[i]);
    }else{
      //take 3, take 2 or only take 1
      long double a = dp[i - 3] + psa[i] - psa[i - 3] - min(shoes[i], min(shoes[i  - 1], shoes[i - 2]));
      long double b = dp[i - 2] + psa[i] - psa[i - 2] - min(shoes[i], shoes[i - 1])/2;
      long double c = dp[i - 1] + shoes[i];
      dp[i] = min(a, min(b, c));
    }
    //cout << dp[i] << ' ';
  }
  cout << dp[n] << endl;
}