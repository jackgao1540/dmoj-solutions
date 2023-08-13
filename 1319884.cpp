#include <iostream>

using namespace std;

long long min(long long a, long long b){
  return a < b ? a : b;
}

int main() {
 int n; long long psa[3005] = {0}, dp[3005][3005] = {0};
 cin >> n;
 for(int i = 1; i <= n; i++){
   cin >> dp[i][i];
   psa[i] = psa[i - 1] + dp[i][i];
 }
 for(int len = 1; len < n; len++){
   for(int lft = 1; lft + len <= n; lft++){
     int rit = lft + len;
     dp[lft][rit] = psa[rit] - psa[lft - 1] - min(dp[lft + 1][rit], dp[lft][rit - 1]);
   }
 }
 cout << dp[1][n] - (psa[n] - dp[1][n]);
}