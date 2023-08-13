#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  long double x, y;
  cout << fixed;
  cout << setprecision(1);
  cin >> x >> y;
  cout << (x * y / 2) << endl;
}