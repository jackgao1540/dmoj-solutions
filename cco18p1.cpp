#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b){
  return a > b ? a : b;
}

int main() {
  int n;
  cin >> n;
  string a = " ", b = " ";
  string t1, t2;
  cin >> t1;
  a += t1;
  vector <int> x, y;
  x.push_back(0);
  y.push_back(0);
  for(int i =0; i <n; i++){
    int d;
    cin >>d;
    x.push_back(d);
  }
  cin >> t2;
  b += t2;
  for(int i =0; i <n; i++){
    int d;
    cin >>d;
    y.push_back(d);
  }
  long dp[1010][1010] = {0};
  //all 1 indexed
  //cout << a << endl << b << endl;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      if(a[i] != b[j] && ((a[i] == 'W' && x[i] > y[j])||(a[i] == 'L' && x[i] < y[j]))){
        dp[i][j] = max(x[i] + y[j] + dp[i - 1][j - 1], max(dp[i - 1][j], dp[i][j - 1]));
      }else{
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
      //cout << dp[i][j] << ' ';
    }
    //cout << endl;
  }
  cout << dp[n][n];
}