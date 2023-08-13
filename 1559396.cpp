#include <bits/stdc++.h>

using namespace std;

int abs(int a, int b){
  if(a > b)return a - b;
  else return b - a;
}

int main() {
  int n, k;
  vector <int> heights;
  cin >> n >> k;
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    heights.push_back(x);
  }
  sort(heights.begin(), heights.end());
  int bestNum = 0;
  for(int l = 0, r = 0; r < n; r++){
    while(abs(heights[r] - heights[l]) > k)l++;
    bestNum = max(bestNum, r - l + 1);
  }
  cout << bestNum << endl;
}