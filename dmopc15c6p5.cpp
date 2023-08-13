#include <bits/stdc++.h>

using namespace std;

const int MM = 3e6+5;
int N, a[MM], K;
long long ans = 0;
deque <int> mx, mi;

int main() {
  scanf("%d %d", &N, &K);
  for(int i = 1; i <= N; i++)scanf("%d", &a[i]);
  for(int L = 1, R = 1; R <= N; R++){
    while(!mx.empty() && mx.back() < a[R])mx.pop_back();
    while(!mi.empty() && mi.back() > a[R])mi.pop_back();
    mx.push_back(a[R]);
    mi.push_back(a[R]);
    while(mx.front() - mi.front() > K){
      if(mx.front() == a[L])mx.pop_front();
      if(mi.front() == a[L])mi.pop_front();
      L++; 
    }
    //cout << L << ' ' << R << endl;
    ans += R - L  + 1;
  }  
  cout << ans << endl;
}