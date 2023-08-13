#include <iostream>
#include <vector>
/*
6 20
 24 5
 4123 13
 4087 15
 444 5
 532 7
 94 20
*/
using namespace std;

vector <int> numP;
vector <int> numS;
int dp[1001][1001] = {0};
int cages, minutes;

int main() {
  cin >> cages >> minutes;
  int x, y;
  for(int i = 0; i < cages; i++){
    cin >> x >> y;
    numP.push_back(x);
    numS.push_back(y);
  }
  for(int i = 1; i <= cages; i++){
    for(int j = 1; j <= minutes; j++){
      //check if current cage is pleasable
      if(numS[i] <= j){
          dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - numS[i]] + numP[i]);
      }else{
          dp[i][j] = dp[i - 1][j];
      }
      //cout << dp[i][j] << " ";
    }
    //cout << endl;
  }
  cout << dp[cages][minutes];
  return 0;
}