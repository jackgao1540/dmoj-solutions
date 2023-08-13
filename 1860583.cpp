#include <bits/stdc++.h>

using namespace std;
int p[2000000];
bool isPrime(int x){
  if(p[x] != 0)return p[x] > 0 ? true : false;
  for(int i = 2; i * i <= x; i++){
    if(x % i == 0){p[x] = -1; return false;}

  }
  p[x] = 1;
  return true;
}

int main() {
  memset(p, 0, sizeof(p));
    int T; 
    scanf("%d", &T);
    for(int i = 0; i < T; i++){
        int n;
        scanf("%d", &n);
        for(int a = 2; a <= n; a++){
            int b = 2 * n - a;
            if(isPrime(a) && isPrime(b)){
              cout << a << ' ' << b << endl;
              break;
            }
        }
    }
    return 0;
}