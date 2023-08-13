#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  unsigned short pillars[1000002] = {0}, pre[1000002] = {0}, post[1000002] = {0};
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> pillars[i];
    pre[i] = max(pillars[i], pre[i - 1]);
  }
  for(int i = n; i >= 1; i--){
    post[i] = max(pillars[i], post[i + 1]); 
  }
  unsigned long long total = 0;
  for(int i = 1; i <= n; i++){
    total += min(pre[i], post[i]) - pillars[i];
  }
  cout << total;
}