#include <bits/stdc++.h>

using namespace std;

int main() {
    int dp[2][1001] = {0};
    int N, T;
    scanf("%d%d",&N, &T);
    for(int i = 1; i <= N; i++){
        int d;
        int t = 0, v = 0;
        scanf("%d", &d);
        for(int j = 1; j <= d; j++){
            int nt, nv;
            scanf("%d%d", &nt, &nv);
            t += nt;
            v += nv;
            for(int k = 0; k <= T; k++){
              if(k < t)dp[i%2][k] = max(dp[i%2][k], dp[(i - 1)%2][k]);
              else{
                dp[i%2][k] = max(dp[i%2][k], max(dp[(i - 1)%2][k], dp[(i - 1)%2][k - t] + v));
              }
            }
        }
    }
    cout << dp[N%2][T] << endl;
    return 0;
}