#include <bits/stdc++.h>

using namespace std;

const int MM = 100005, MOD = 1000000007;

int main() {
  int n, m;
  scanf(" %d %d", &n, &m);
  if(m == 1)printf("1\n");
  else if(m == 2){
    long f[MM] = {0};
    f[0] = 0;
    f[1] = 1;
    f[2] = 1;
    for(int i = 3; i <= n; i++){
      f[i] = f[i - 1]%MOD + f[i - 3]%MOD;
      f[i] %= MOD;
    }
    printf("%ld\n", f[n]);
  }else{
    /* A(n)=A(n−1)+B(n−2)+C1(n−3)
      B(n)=A(n−2)+C2(n−3)+D(n−1)+D(n−3)
      C1(n)=A(n−2)+C2(n)
      C2(n)=A(n−1)+A(n−2)+C2(n−3)+D(n−1)+D(n−3)
      D(n)=A(n)+B(n−1) */
    long A[MM], B[MM], C1[MM], C2[MM], D[MM];
    A[1] = 1; D[1] = 1;
    A[2] = 1; B[2] = 1; C1[2] = 2; C2[2] = 2; D[2] = 1;
    for(int i = 3; i <= n; i++){
      A[i] = (A[i - 1] + B[i - 2] + C1[i - 3])%MOD;
      B[i] = (A[i - 2] + C2[i - 3] + D[i - 1] + D[i - 3])%MOD;
      C2[i] = (A[i - 1] + A[i - 2] + C2[i - 3] + D[i - 1] + D[i - 3])%MOD;
      C1[i] = (A[i - 2] + C2[i])%MOD;
      D[i] = (A[i] + B[i - 1])%MOD;
    }
    printf("%ld\n", A[n]);
  }
}