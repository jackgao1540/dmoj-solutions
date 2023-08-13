#include <bits/stdc++.h>

using namespace std;
const int MV =1e6 + 2, MM = 2e5 + 5;
int N, Q, LOG, a[MM], l[MM], pre[2*MV], st[18][MM];

int rmq(int x, int y){
  if(x > y)return 0;
  int k = log2(y - x + 1);
  return max(st[k][x], st[k][y - (1 << k) + 1]);
}

int main() {
  scanf("%d%d", &N, &Q); LOG = log2(N);
  for(int i = 1; i <= N; i++){
    scanf("%d", &a[i]);
    a[i] += MV;
    l[i] = min(l[i - 1] + 1, i - pre[a[i]]);
    pre[a[i]] = i;
    st[0][i] = l[i];
  }

  for(int i = 1; i <= LOG; i++){
    for(int j = 1; j + (1 << i) - 1 <= N; j++){
      st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i- 1))]);
    }
  }
  for(int i = 1, x, y; i <= Q; i++){
    scanf("%d%d", &x, &y);
    int lo = x, hi = y, lst = y + 1;
    while(lo <= hi){
      int mid = (lo + hi)/2;
      if(mid - l[mid] + 1 <= x)lo = mid + 1;
      else{
        lst = mid;
        hi = mid - 1;
      }
    }
    printf("%d\n", max(lst - x, rmq(lst, y)));
  }
}