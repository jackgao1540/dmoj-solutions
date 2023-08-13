#include <iostream>

using namespace std;

int max(int a, int b){
  return a > b ? a : b;
}

int main() {
  int n;
  cin >> n;
  long long items[1000001] = {0};
  long long  dp[1000001] = {0};
  for(int i = 1; i <= n; i++){
    cin >> items[i];
  }
  dp[1] = max(items[1], 0);
  for(int i = 2; i <= n; i++){
    dp[i] = max(items[i] + dp[i - 2], dp[i - 1]);
  }
  cout << dp[n];
}