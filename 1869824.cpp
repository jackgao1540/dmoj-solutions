#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, mod=1e9+7, dp[3003][3003], ans; char s[3003];
int main(){
    scanf("%d %s", &N, s+1); dp[1][1] = 1;
    for(int i=2; i<=N; i++){
        for(int j=1; j<=i; j++){
            if(s[i-1] == '<') dp[i][j] = (dp[i][j-1] + dp[i-1][j-1])%mod;
            else dp[i][j] = ((dp[i][j-1] + dp[i-1][i-1])%mod - dp[i-1][j-1] + mod)%mod;
        }
    }
    printf("%d\n", dp[N][N]);
}