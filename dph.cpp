#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

int main() {
  int rows, cols;
  long dp[2][1001] = {0};
  dp[0][0] = 1;
  cin >> rows >> cols;
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      char c; 
      cin >> c;
      if(c == '#')dp[i%2][j] = 0;
      else{
        if(i == 0 && j == 0)dp[i%2][j] = 1;
        else if(i == 0)dp[i%2][j] = dp[i%2][j - 1];
        else if(j == 0) dp[i%2][j] = dp[(i - 1)%2][j];
        else dp[i%2][j] = (dp[i%2][j - 1]%MOD + dp[(i - 1)%2][j]%MOD)%MOD;
      }
      //cout << dp[i%2][j] << ' ';
    }
    //cout << endl;
  }
  cout << dp[(rows - 1)%2][cols - 1] << endl;
}