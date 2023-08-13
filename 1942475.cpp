#include <bits/stdc++.h>

using namespace std;

const int MM = 1e4 + 2;
int N, M ,dp[MM], ans;
map <int, int> mp[MM];

int main() {
    scanf(" %d %d", &N, &M);
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    mp[0][0] = 0;
    for(int i = 1; i < MM; i++){
        mp[i][0] = -1;
    }
    for(int i = 1, x; i <= N; i++){
        scanf("%d", &x);
        for(int j = x; j < MM; j++){
            int t = dp[j - x] + 1;
            if(t < dp[j]){
                dp[j] = t;
                mp[j][i] = dp[j];
            }
        }
    }
    ans = -1;
    for(int i = 1, val, typ; i <= M; i++){
        scanf("%d %d", &val, &typ);
        if(ans != -1){val ^= ans;
        typ ^= ans;}
        auto it = mp[val].upper_bound(typ);
        it--;
        ans = it->second;
        printf("%d\n", it->second);
    }
    return 0;
}