#include <iostream>
#include <vector>

using namespace std;

int min(int a, int b){
  return a < b ? a : b;
}

int abs(int a){
  return a < 0 ? -a : a;
}
int main() {
  int numFrogs;
  vector <int> frogs;
  vector <unsigned long long> dp;
  cin >> numFrogs;
  for(int i = 0; i < numFrogs; i++){
    int p;
    cin >> p;
    frogs.push_back(p);
    dp.push_back(0);
  }
  dp[0] = 0;
  dp[1] = abs(frogs[1] - frogs[0]);
  for(int i = 2; i < numFrogs; i++){
    dp[i] = min(dp[i - 1] + abs(frogs[i - 1] - frogs[i]), dp[i - 2] + abs(frogs[i - 2] - frogs[i]));
    //cout << dp[i] << endl;
  }
  cout << dp[numFrogs - 1];
  return 0;
}