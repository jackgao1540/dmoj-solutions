#include <bits/stdc++.h>
using namespace std;
const int MM = 150002;
int id[3]={0, 1, 2}, v[3][MM], dp[3][MM], n, ans = INT_MAX;
int main(){
    scanf("%d", &n);
    for(int i=0; i<3; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &v[i][j]);
    do{
        memset(dp, 0x3f, sizeof(dp));
        dp[0][0] = v[id[0]][0];
        for(int i=0; i<3; i++){
            for(int j=1; j<n; j++){
                if(i==0) dp[i][j] = dp[i][j-1] + v[id[i]][j];
                else dp[i][j] = min(dp[i-1][j-1], dp[i][j-1]) + v[id[i]][j];
            }
        }
        ans = min(ans, dp[2][n-1]);
    }while(next_permutation(id, id+3));
    printf("%d\n", ans);
    return 0;
}