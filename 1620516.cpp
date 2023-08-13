#include <bits/stdc++.h>

using namespace std;

double findMaxAverage(vector<double> nums, int k) {
  int n = nums.size();
  vector<double> sums(n + 1, 0);
  double left = *min_element(nums.begin(), nums.end());
  double right = *max_element(nums.begin(), nums.end());
  while (right - left > 1e-5) {
    double minSum = 0, mid = left + (right - left) / 2;
    bool check = false;
    for (int i = 1; i <= n; ++i) {
      sums[i] = sums[i - 1] + nums[i - 1] - mid;
      if (i >= k) {
        minSum = min(minSum, sums[i - k]);
      }
      if (i >= k && sums[i] > minSum) {check = true; break;} 
    }
    if (check) left = mid;
    else right = mid;
  }
  return left;
}

int main(){
  int n, k;
  vector <double> nums;
  cin >> n >> k;
  double x;
  for(int i = 0; i < n; i++){
    cin >> x;
    nums.push_back(x);
  }
  cout << fixed;
  cout << setprecision(10);
  cout << findMaxAverage(nums, k);
}