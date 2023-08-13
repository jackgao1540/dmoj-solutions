#include <iostream>

using namespace std;

pair <int, int> max(pair <int, int> a, pair <int, int> b){
  if(a.first > b.first){
    return a;
  }else if(a.first < b.first){
    return b;
  }else{
    if(a.second <= b.second){
      return a;
    }else {
      return b;
    }
  }
}

int main() {
  int n, t; 
  cin >> n;
  int teachers[3][50];
  //happiness, energy consumption and preparation time
  for(int i = 0; i < n; i++){
    cin >> teachers[0][i] >> teachers[1][i] >> teachers[2][i];
  }
  cin >> t;
  pair <int, int> dp[2][1001];//first is the max happiness, second is min time in seconds
  pair <int, int> zero;
  zero.first = 0;
  zero.second = 0;
  //make all zero
  for(int i = 0; i < 2; i++){
    for(int j = 0; j <= t; j++){
      dp[i][j] = zero;
    }
  }
  //actual dp
  for(int i = 0; i < n; i++){
    int hi, ei, ci, numSeconds;
    hi = teachers[0][i];
    ei = teachers[1][i];
    ci = teachers[2][i];
    numSeconds = 1;
    int totalHappiness = hi;
    int curVal = 0;
    while(hi - (numSeconds - 1) * ei > 0 && numSeconds * ci <= t){
      int curHi = hi - (numSeconds - 1) * ei;
      curVal += curHi;
      //start dp
      int curCost = ci * numSeconds;
      for(int j = 0; j <= t; j++){
        if(j == 0){
          //do nothing
          continue;
        }else 
        if(i == 0){
          //can't take from last row
          if(j >= curCost){
            dp[i%2][j] = max(dp[i%2][j], make_pair(curVal, numSeconds));
          }
        }else{
          if(j >= curCost){
            dp[i%2][j] = max(dp[i % 2][j], max(make_pair(curVal + dp[(i - 1)%2][j - curCost].first, dp[(i - 1)%2][j - curCost].second + numSeconds), dp[(i - 1)%2][j]));
          }else{
            dp[i%2][j] = max(dp[i%2][j], dp[(i - 1)%2][j]);
          }
        }
      }
      //over
      numSeconds++; 
    }
  }
  //test
  /*for(int i = 0; i < n; i++){
    for(int j = 0; j <= t; j++){
      cout << "(" << dp[i%2][j].first << ", " << dp[i%2][j].second << ") ";
    }
    cout << endl;
  }*/

  cout << dp[(n - 1)%2][t].first << endl << dp[(n - 1)%2][t].second;
}