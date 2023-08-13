#include <iostream>

using namespace std;

int min(int a, int b){
  return a < b ? a : b;
}

int main() {
  int grid[1001][1001] = {0}, dp[1001][1001] = {0};
  int l, d;
  cin >> l >> d;
  for(int i = 0; i < d; i++){
    for(int j = 0; j < l; j++){
      cin >> grid[i][j];
    }
  }
  //grid is d units down, l units long, so its grid[d][l]
  dp[0][0] = grid[0][0];
  for(int i = 1; i < l; i++){
    dp[0][i] = grid[0][i] + dp[0][i - 1];
  }
  for(int i = 1; i < d; i++){
    //sweep left
    dp[i][0] = grid[i][0] + dp[i - 1][0];
    for(int j = 1; j < l; j++){
      dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
    }
    //sweep right
    dp[i][l - 1] = min(dp[i][l - 1], grid[i][l - 1] + dp[i - 1][l - 1]);
    for(int j = l - 2; j >= 0; j--){
      dp[i][j] = min(dp[i][j], grid[i][j] + dp[i][j + 1]);
    }
  }
  int x, y;
  cin >> x >> y;
  cout << dp[y][x] << endl;
  /*for(int i = 0; i < d; i++){
    for(int j = 0; j < l; j++){
      cout << dp[i][j] << ' ';
    }
    cout << endl;
  }*/
}