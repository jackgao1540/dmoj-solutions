#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    int cur  = 0;
    for(int j = 0; j < n; j++){
      int d;
      cin >> d;
      cur |= d;
    }
    cout << cur << ' ';
  }
}