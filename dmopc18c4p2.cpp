#include <iostream>

using namespace std;

/*
7
1 2 3 4 6 9 17
*/

int main() {
  int n;
  cin >> n;
  int items[n];
  int sum = 0;
  for(int i = 0; i < n; i++){
    cin >> items[i];
    sum += items[i];
  }
  //have
  int w = (sum / 2) + 1;
  bool dp[w] = {0};
  dp[0] = 1;
  int maxCanMake = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < w; j++){
      int cur = items[i];
      if(dp[j] == 1 && j + cur <= w- 1){
        dp[j + cur] = 1;
        maxCanMake = j + cur;
      }
    }
  }
  cout << (sum - maxCanMake) - maxCanMake; 
}