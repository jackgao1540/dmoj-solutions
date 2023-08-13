#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k, maxPieces = 0;
  long dp[2][1002] = {0}, numPieces[1002] = {0};
  cin >> n >> k; 
  for(int i = 0; i < n; i++){
    int d;
    cin >> d;
    if(d > maxPieces)maxPieces = d;
    numPieces[d]++;
  }
  for(int i = 0; i <= maxPieces; i++){
    for(int j = 0; j <= i; j++){
      if(j == 0)dp[i%2][j] = 1;
      else if(i == 0){
        dp[i%2][j] = 1;
      }else if(i == 1){
        dp[i%2][j] = numPieces[i] % 998244353;
      }else{
        //i >= 2 and j >= 1
        dp[i%2][j] = (dp[(i - 1)%2][j] % 998244353) + (numPieces[i]%998244353) * (dp[(i - 1) % 2][j - 1] % 998244353);
        dp[i%2][j] %= 998244353;
      }
      //cout << dp[i%2][j] << ' ';
    }
    //cout << endl;
  }
  cout << dp[maxPieces%2][k] % 998244353 << endl;
}