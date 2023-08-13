#include <iostream>

using namespace std;

long long f(long long a) {
     long long res[] = {a,1,a+1,0};
     return res[a%4];
}

long long getXor(long long a, long long b) {
     return f(b)^f(a-1);
}

int main() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    long long a, b;
    cin >> a >> b;
    cout << getXor(a, b) << endl;
  }
}