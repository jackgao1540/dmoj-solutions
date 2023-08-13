#include <bits/stdc++.h>
 
using namespace std; 

/*int dp[302][302] = {0};
string s;

bool isPair(char a, char b){
  return (a == '(' && b == ')')||(a == '[' && b == ']')||(a == '{' && b == '}');
}

int recur(int l, int r){
  if(dp[l][r] > 0)return dp[l][r];
  else if(l == r)return 1;
  else if(l > r)return 0;
  else if(l + 1 == r){
    if(isPair(s[l], s[r]))return dp[l][r] = 0;
    else return dp[l][r] = 2;
  }
  else if(isPair(s[l], s[r])){
    return dp[l][r] = recur(l + 1, r - 1); 
  }else{
    dp[l][r] = INT_MAX;
    for(int k = l; k < r; k++){
      dp[l][r] = min(dp[l][r], recur(l, k) + recur(k + 1, r));
    }
    return dp[l][r];
  }
}

int main(){
  cin >> s;
  if(s.size() == 0)cout << 0;
  else cout << recur(0, s.size() - 1) << endl;
}*/

string s; int dp[302][302] = {0};

bool isPair(char a, char b){
  return (a == '(' && b == ')')||(a == '[' && b == ']')||(a == '{' && b == '}');
}

int fun(int l, int r){
  if(l > r)return 0;
  if(dp[l][r] > 0)return dp[l][r];
  if(l == r)return 1;
  else if(l + 1 == r)return isPair(s[l], s[r]) ? 0 : 2;
  int ans = s.size() + 1;
  if(isPair(s[l], s[r])) ans = fun(l + 1, r - 1);
  for(int k = l; k < r; k++){
    ans = min(ans, fun(l, k) + fun(k + 1, r));
  }
  return dp[l][r] = ans;
}

int main(){
  cin >> s;
  memset(dp, -1, sizeof(dp));
  cout << fun(0, s.size() - 1) << endl;
}