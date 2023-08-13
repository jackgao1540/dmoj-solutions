#include <bits/stdc++.h>
using namespace std;
int N, K, mask[1<<10], cnt[1<<10], tot; long long dp[101][11][1<<10], ans;
int main(){
    scanf("%d %d", &N, &K);
    for(int i=0; i<(1<<N); i++){
       if(!(i&(i<<1)) && !(i&(i>>1))){
            mask[tot]=i; cnt[tot] = __builtin_popcount(i); tot++;
        }
    }
    for(int i=0; i<tot; i++) dp[cnt[i]][1][mask[i]]= 1;
    for(int k=0; k<=K; k++){
        for(int i=2; i<=N; i++){
            for(int j=0; j<tot; j++){
                if(cnt[j] > k) continue;
                for(int p=0; p<tot; p++){
                    if(cnt[j] + cnt[p] > k || (mask[j]&mask[p])>0 || (mask[j] & (mask[p]<<1)) > 0
                       || (mask[j] & (mask[p] >> 1)) >0 )  continue;
                    dp[k][i][mask[j]] += dp[k - cnt[j]][i-1][mask[p]];
                }
            }
        }
    }
    for(int i=0; i<tot; i++) ans += dp[K][N][mask[i]];
    printf("%lld\n", ans);
}