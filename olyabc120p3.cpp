#include <bits/stdc++.h>

using namespace std;

int min(int a, int b){return a < b ? a : b;}

int main() {
  string s;
  cin >> s;
  int cnt = 0;
  for(int i = 0; i < s.size(); i++){
    cnt += s[i] == '0';
  }
  cout << 2 * min(cnt, s.size() - cnt) << endl;
}