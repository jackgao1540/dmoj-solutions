#include <iostream>

using namespace std;

int max(int a, int b){
  return a > b ? a : b;
}

int main() {
  int n;
  cin >> n;
  int happiness[3][n];
  int dp[3][n];
  for(int i = 0; i < n; i++){
    cin >> happiness[0][i] >> happiness[1][i] >> happiness[2][i];
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < 3; j++){
      //dp[j][i]
      if(i == 0)dp[j][i] = happiness[j][i];
      else dp[j][i] = max(dp[(j + 1)%3][i - 1], dp[(j + 2)%3][i - 1]) + happiness[j][i];
    }
  }
  cout << max(max(dp[0][n - 1], dp[1][n - 1]), dp[2][n - 1]);
}