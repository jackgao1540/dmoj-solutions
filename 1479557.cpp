#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector <int> nums;
  for(int i = 0; i < n; i++){
    int d;
    cin >> d;
    nums.push_back(d);
  }
  int maxSum = 0;
  for(int i = 0; i < n; i++){
    int d;
    cin >> d;
    nums[i] -= d;
    if(nums[i] > 0)maxSum += nums[i];
  }
  cout << maxSum << endl;
}