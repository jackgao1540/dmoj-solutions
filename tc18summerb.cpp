#include <bits/stdc++.h>

using namespace std;

int countBits(int c){
  int count = 0;
  while(c != 0){
    count += c & 1;
    c /= 2;
  }
  return count;
}

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if(b + c != a)cout << 0;
  else{
    //find number of bits in c
    cout << (1 << countBits(c));
  }
}