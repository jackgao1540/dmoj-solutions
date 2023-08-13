#include <iostream>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  int is = true;;
  for(int i = 1; i <= n; i++){
    int d;
    cin >> d;
    if(d % k != i % k){
      is = false;
      break;
    }
  }
  cout << (is ? "YES" : "NO");
}