#include <bits/stdc++.h>

using namespace std;
 
string s;
int dp[256][256] = {0};

int longestPalindrome(int l, int r){
  int ret = 0;
  if(dp[l][r] > 0)return dp[l][r];
  if(l == r)return dp[l][r] = 1;
  if(s[l] == s[r] && l + 1 == r)return dp[l][r] = 2;
  if(s[l] == s[r])return dp[l][r] = 2 + longestPalindrome(l + 1, r - 1);
  return dp[l][r] = max(longestPalindrome(l + 1, r), longestPalindrome(l, r - 1));
}

int main() {
  for(int l = 0; l < 5; l++){
    s = "";
    memset(dp, 0, sizeof(dp));
    cin >> s;
    printf("%d\n", longestPalindrome(0, s.size() - 1));
  }
}