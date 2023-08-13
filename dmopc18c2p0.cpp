#include <iostream>

using namespace std;

int main() {
  int n, a , r;
  cin >> n >> a >> r;
  cout << (r/a < n? r/a : n);
}