#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n; 
  vector <int> candies;
  long sum = 0;
  for(int i = 0; i < n; i++){
    int d;
    cin >> d;
    candies.push_back(d);
    sum += d;
  }
  int score = sum / n;
  int ans = 0;
  for(int i = 0; i < n; i++){
    if(candies[i] > score)ans += candies[i] - score;
  }
  cout << ans << endl;
}