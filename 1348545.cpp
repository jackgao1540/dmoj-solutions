#include <bits/stdc++.h>

using namespace std;

int dp[1001][1001] = {0};
int psa[1001] = {0};

int max(int a, int b){
  return a >= b ? a : b;
}

void clearDP(){
  for(int i = 0; i < 1001; i++){
    psa[i] = 0;
    for(int j = 0; j < 1001; j++){
      dp[i][j] = 0;
    }
  }
}

int val(int i){return psa[i] - psa[i - 1];}

int recur(int l, int r){
  if(dp[l][r] > 0)return dp[l][r];
  if(l == r){
    dp[l][r] = val(l);
  }else if(l + 1 == r){
    dp[l][r] = max(val(r), val(l));
  }else{
    //return max if you choose left side or right side
    int a, b;
    //a is left side, b is right side
    //find the max of l + 1 and r 
    a = val(l);
    b = val(r);
    if(val(r) > val(l + 1)){
      //take r
      a += recur(l + 1, r - 1);
    }else{
      //take l + 1
      a += recur(l + 2, r);
    }
    //find b
    if(val(l) >= val(r - 1)){
      b += recur(l + 1, r - 1);
    }else{
      b += recur(l, r - 2);
    }
    dp[l][r] = max(a, b);
  }
  //cout << dp[l][r] << ' ' << l  << ", " << r << endl;
  return dp[l][r];
}

int main() {
  int n;
  int gameNo = 1;
  cin >> n;
  while(n != 0){
    clearDP();
    vector <int> cards;
    cards.push_back(0);
    for(int i = 0; i < n; i++){
      int c;
      cin >> c;
      cards.push_back(c);
      psa[i + 1] = psa[i] + c;
      //cout << psa[i + 1] << ' ';
    }
    //cout << endl;
    //perform the recur
    int d = recur(1, n);
    int ans = d - (psa[n] - d);
    cout << "In game " << gameNo << ", the greedy strategy might lose by as many as " << ans << " points." << endl;
    cin >> n;
    gameNo++;
  }
}