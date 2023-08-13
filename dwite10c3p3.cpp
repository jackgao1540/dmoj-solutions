#include <bits/stdc++.h>

using namespace std;

//dp[i] = 3*dp[i-2] + 2*dp[i -2] + 2*dp[i - 4]... 

int dp[31] = {0};

int recur(int d){
  if(d % 2 != 0)return 0;
  if(dp[d] != 0)return dp[d];
  else{
    return dp[d] = (4 * recur(d - 2) - recur(d - 4) + 1000000 ) % 1000000; 
  }
}

int main() {
   for(int i = 0; i < 5; i++){
     int n;
     cin >> n;
     dp[0] = 1;
     dp[1] = 0;
     dp[2] = 3;
     dp[3] = 0;
     dp[4] = 11;
     if(n % 2 != 0)cout << 0 << endl;
     else cout << recur(n) << endl;
   }
}