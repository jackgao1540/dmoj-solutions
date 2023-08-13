#include <bits/stdc++.h>

using namespace std;

int n, maxLen = 0;
int numbers[100002] = {0};
int dp[31] = {0};

void count(int n){
  int bits[31] = {0};
  int count = 0;
  while(n != 0){
    if(n & 1)bits[count] = 1;
    count++;
    n /= 2;
  }
  //now have list of bits
  //find the maximum from all of the dp's
  int maxLength = 0;
  for(int i = 0; i < 31; i++){
    if(bits[i] == 1 && dp[i] > maxLength)maxLength = dp[i];
  }
  maxLength++;
  for(int i  = 0; i < 31; i++){
    if(bits[i])dp[i] = maxLength;
  }
  if(maxLength > maxLen)maxLen = maxLength;
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> numbers[i + 1];
  }
  for(int i = 1; i <= n; i++){
    int cur = numbers[i];
    count(cur);
  }
  cout << maxLen << endl;
}