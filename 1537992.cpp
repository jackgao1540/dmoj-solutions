#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, dp[2][257] = {0}, grid[257][257] = {0};
  for(int k = 0; k < 5; k++){
  n = 0;
  memset(dp, 0, sizeof(dp));
  memset(grid, 0, sizeof(grid));
  cin >> n; 
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      char c;
      cin >> c;
      if(c != '.')grid[i][j] = 1;
      else grid[i][j] = 0;
    }
  }
  long tot = 0;
  for(int i = n; i > 0; i--){
    for(int j = 1; j <= n; j++){
      if(grid[i][j] == 0) {dp[i%2][j] = 0;continue;}
      else{
        if(i == n || j == n || j == 1) dp[i%2][j] = 1;
        else{
          dp[i%2][j] = min(dp[(i + 1)%2][j], min(dp[(i + 1)%2][j + 1], dp[(i + 1)%2][j - 1])) + 1;
        }
        tot += dp[i%2][j];
      }
    }
  }
  cout << tot << endl;
  }
}