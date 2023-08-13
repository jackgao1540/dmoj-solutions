#include <iostream>

using namespace std;

int main() {
  long n;
  cin >> n;
  //find largest 2^x that is less than n, and output x^(x + 1) - 1
  long x = 0;
  while(n > 1){
    n/=2;
    x++;
  }
  for(long i = 0; i <= x; i++){
    cout << 1;
  }
}