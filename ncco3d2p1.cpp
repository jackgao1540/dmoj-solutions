#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  int log = log2(n);
  int mx[16][50002], mi[16][50002];
  for(int i = 1; i <= n; i++){
    scanf("%d", &mx[0][i]);
    mi[0][i] = mx[0][i];
  }
  for(int i = 1; i <= 16; i++){
    for(int j = 1; j + (1 << i) - 1 <= n; j++){
      mx[i][j] = max(mx[i - 1][j], mx[i - 1][j + (1 <<(i - 1))]);
      mi[i][j] = min(mi[i - 1][j], mi[ i -1][j + (1 << (i - 1))]);
    }
  }
  for(int i = 1; i <= q; i++){
    int x, y, len;
    scanf("%d%d", &x, &y);
    int k = log2(y - x + 1);
    printf("%d\n", max(mx[k][x], mx[k][y - (1 << k) + 1]) - min(mi[k][x], mi[k][y - (1 << k) + 1]));
  }
}