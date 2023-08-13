#include <bits/stdc++.h>

using namespace std;

vector <int> ans;

void recur(int n, int p, int score){
  ans.push_back(n - 1 + score);
  if(n == 1)ans.push_back(score);
  //check to find all the factors
  for(int i = p, up = sqrt(n); i <= up; i++){
    if(n % i == 0) recur(n / i, i, score + i - 1);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  recur(n, 2, 0);
  sort(ans.begin(), ans.end());
  int tot = unique(ans.begin(), ans.end()) - ans.begin();
  printf("%d\n", tot);
  for(int i = 0; i < tot; i++){
    printf("%d ", ans[i]);
  }
}