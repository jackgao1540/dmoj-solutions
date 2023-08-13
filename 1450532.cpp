#include <bits/stdc++.h>

using namespace std;

int abs(int a){return a < 0 ? -a : a;}

int gcd(int a, int b){
  if(a < b){
    int t = a;
    a = b;
    b = t;
  }
  if(b == 0)return a;
  else return gcd(b, a % b);
}

int main() {
  int n;
  short dp[2][10000005] = {0};
  memset(dp, -1, sizeof(dp));
  cin >> n;
  dp[0][0] = 0;
  int Gcd = 0;
  vector <pair <int, int>> items;
  int sum = 0;
  for(int i = 0; i < n; i++){
    int a, b;
    cin >> a >> b;
    items.push_back(make_pair(a, b));
    sum += a * b;
    Gcd = gcd(Gcd, b);
  }
  //cout << sum << endl;
  //dp
  sum /= Gcd;
  int maxMake = 0;
  for(int i = 1; i <= n; i++){
    for(int j = 0; j <= sum/2; j++){
      int numCanTake = items[i - 1].first, calories = items[i - 1].second/Gcd;
      if(j == 0)dp[i%2][j] = 0;
      else if(j < calories){
        dp[i%2][j] = dp[(i - 1)%2][j] >= 0 ? 0 : -1;
        if(dp[i%2][j] != -1)maxMake = max(maxMake, j);
      }else{
        if(dp[(i - 1)%2][j] >= 0)dp[i%2][j] = 0;
        else if(dp[i%2][j - calories] >= 0 && dp[i%2][j - calories] < numCanTake){
          dp[i%2][j] = dp[i%2][j - calories] + 1;
        }else dp[i%2][j] = -1;
        if(dp[i%2][j] != -1)maxMake = max(maxMake, j);
        /*int count = 0, cur = j;
        while(count <= numCanTake && cur >= 0){
          if(dp[(i - 1)%2][cur] == true){
            dp[i%2][j] = true;
            maxMake = max(maxMake, j);
            //cout << maxMake << endl;
            break;
          }
          //done
          count++;
          cur -= calories;
        }*/
      }
    }
  }
  cout << abs((sum - maxMake) - maxMake) * Gcd << endl;
}