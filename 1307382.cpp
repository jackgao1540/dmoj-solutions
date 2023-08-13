#include <iostream>

using namespace std;

int max(int a, int b){
  return a > b ? a : b;
}

int abs(int d){
  if(d < 0)return -d;
  else return d;
}

int findDiff(int t, int d){
  return abs(t - 2 * d);
}

int main() {
  for(int k = 0; k < 5; k++){
    int n;
    cin >> n;
    int numbers[31] = {0};
    int dp[31][16000] = {0};
    int total = 0;
    for(int i =0; i < n; i++){
      cin >> numbers[i];
      total += numbers[i];
    }
    int minDiff = 999999999;
    //do dp
    for(int i = 0; i <= n; i++){
      dp[i][0] = 1;
    }
    dp[0][numbers[0]] = 1;
    for(int i = 1; i < n; i++){
      for(int j = 1; j <= total/2 + 1; j++){
        if(numbers[i] <= j){
          dp[i][j] = max(dp[i - 1][j - numbers[i]], dp[i - 1][j]);
        }else dp[i][j] = dp[i - 1][j];
        //cout << dp[i][j] << ' ';
        if(findDiff(total, j) < minDiff && dp[i][j] == 1)minDiff = findDiff(total, j);
      }
      //cout << endl;
    }
    cout << minDiff << endl;
  }
}