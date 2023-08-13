#include <bits/stdc++.h>

using namespace std;

void bin(int x){
  if(x == 0)cout << "0000" << endl;
  int pow = log2(x);
  int p;
  if((pow + 1) % 4 == 0){
    p = pow;
  }else{
    int d = pow / 4;
    d += 1;
    d *= 4;
    d -= 1;
    p = d;
  }
  string s = "";
  while(p >= 0){
    if((x & (1 << p)) != 0){
      s += '1';
    }else s += '0';
    if(p % 4 == 0)s += ' ';
    p--;
  }
  cout << s << endl;
  return;
}

int main() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    int d;
    cin >> d;
    bin(d);
  }
  return 0;
}