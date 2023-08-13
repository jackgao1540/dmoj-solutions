#include <bits/stdc++.h>

using namespace std;

int n, m; vector <int> lft, rt;

int abs(int a){
  if(a > 0)return a;
  else return -a;
}

bool check(int val){
  int l = 0, r = 0, numPairs = 0;
  while(l < n && r < m){
    if(abs(lft[l] - rt[r]) <= val){
      numPairs++;
      l++;
      r++;
    }else if(lft[l] < rt[r]){
      l++;
    }else{
      r++;
    }
  }
  return numPairs == (min(n, m));
}

int main() {
  int lo = 0, hi = 1e9, ans = INT_MAX;
  scanf("%d%d", &n, &m);
  for(int i = 0; i < n; i++){
    int x;
    scanf("%d", &x);
    lft.push_back(x);
  }
  for(int i = 0; i < m; i++){
    int x;
    scanf("%d", &x);
    rt.push_back(x);
  }
  sort(lft.begin(), lft.end());
  sort(rt.begin(), rt.end());
  while(lo <= hi){
    int mid = (lo + hi)/2;
    if(check(mid)){
      ans = mid;
      hi = mid - 1;
    }else{
      lo = mid + 1;
    }
  }
  printf("%d\n", ans);
}