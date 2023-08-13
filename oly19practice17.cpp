#include <bits/stdc++.h> 
  
using namespace std; 
  
int main(){
  int n;
  cin >> n;
  int sums[100002] = {0};
  int r= 1;
  for(int i = 0; i < n; i++){
    int d;
    cin >> d;
    if(d > r)r = d;
    sums[d]++;
  }
  int dp[100002] = {0};
  for(int i = 1; i <= r; i++){
    if(sums[i] > 0)dp[i] = max(dp[i - 1], (i >= 2 ? dp[i - 2] : 0 )+ sums[i] * i);
    else dp[i] = dp[i - 1];
  }
  cout << dp[r] << endl;
}