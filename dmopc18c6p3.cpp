#include <bits/stdc++.h>

using namespace std;

const int MM = 200002;
int n, m, p[MM], cnt;

int find_set(int d){
  if(p[d] != d)p[d] = find_set(p[d]);
  return p[d];
}

int main(){
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= n; i++){
    p[i] = i;
  }
  for(int i = 1, x, y; i <= m; i++){
    scanf("%d %d", &x, &y);
    int fx = find_set(x), fy = find_set(y);
    if(fx != fy)p[fx] = fy;
    else cnt++;
  }
  if(cnt <= 1)printf("YES");
  else printf("NO");
}