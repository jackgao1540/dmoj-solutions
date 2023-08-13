#include <bits/stdc++.h>

#define ull unsigned long long

using namespace std;
//2 ^ 63 = 9223372036854775807
ull dp[34] = {0};
int largestKnown;

ull findFact(int n){
  if(dp[n] > 0)return dp[n];
  for(int i = largestKnown + 1; i <= n; i++){
    dp[i] = dp[i - 1] % 4294967296;
    dp[i] *= i;
    dp[i] %= 4294967296;
  }
  return dp[n];
}

int main() {
  int n;
  cin >> n;
  dp[0] = 1;
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 6;
  dp[4] = 24;
  dp[5] = 120;
  dp[6] = 720;
  dp[7] = 5040;
  dp[8] = 40320;
  dp[9] = 362880;
  dp[10] = 3628800;
  dp[11] = 39916800;
  dp[12] = 479001600;
  largestKnown = 12;
  for(int i = 0; i < n; i++){
    ull c;
    cin >> c;
    if(c >= 34)cout << 0 << endl;
    else cout << findFact(c) << endl;
  }
}