//dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w] + psa[j] - psa[j - w])
#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b){
  return a > b ? a : b;
}

int main(){
  int numCases;
  cin >> numCases;
  for(int d = 0; d < numCases; d++){
    int p, b, w;
    cin >> p >> b >> w;
    vector <int> pinSums;
    pinSums.push_back(0);
    long dp[2][30001] = { 0 };
    for(int i = 1; i <= p; i++){
      int t;
      cin >> t;
      pinSums.push_back(0);
      if(i > 1)pinSums[i] = pinSums[i - 1] + t;
      else pinSums[i] = t;
      //cout << pinSums[i] << ' ';
    }
    //dp
    for(int i = 0; i < b; i++){
      for(int j = 0; j <= p; j++){
        if(j == 0)dp[i%2][j] = 0;
        else if(i == 0){
          //1 ball
          dp[i%2][j] = max(pinSums[j] - (j >= w ? pinSums[j - w] : 0), dp[i%2][j - 1]);
        }else{
          if(j >= w){
            dp[i%2][j] = max(dp[(i)%2][j - 1], dp[(i - 1)%2][j - w] + pinSums[j] - pinSums[j - w]);
          }else{
            dp[i%2][j] = dp[(i - 1)%2][j];
          }
        }
        //cout << dp[i%2][j] << ' '; 
      }
      //cout << endl;
    }
    cout << dp[(b - 1)%2][p] << endl;
  }
}