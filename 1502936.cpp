#include <bits/stdc++.h>

using namespace std;

int n, m;
bool dfa[10001][10001];
//even is black, odd is white
//use 2d difference arrayddg
int main() {
  memset(dfa, false, sizeof(dfa));
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    int x1, y1, w, h;
    cin >> x1 >> y1 >> w >> h;
    int x2 = x1 + w - 1, y2 = y1 + h - 1;
    if(x2 >= n)x2 = n - 1;
    if(y2 >= n)y2 = n - 1;
    dfa[x1][y1] ^= true;
    if(x2 + 1 < n)dfa[x2 + 1][y1] ^= true;
    if(y2 + 1 < n)dfa[x1][y2 + 1] ^= true;
    if(x2 + 1 < n && y2 + 1 < n)dfa[x2 + 1][y2 + 1] ^= true;
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(i > 0)dfa[i][j] ^= dfa[i - 1][j];
      if(j > 0)dfa[i][j] ^= dfa[i][j - 1];
      if(i > 0 && j > 0)dfa[i][j] ^= dfa[i - 1][j - 1];
    }
  }
  int cnt = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cnt += (int)(dfa[i][j]);
    }
  }
  cout << cnt << endl;
}