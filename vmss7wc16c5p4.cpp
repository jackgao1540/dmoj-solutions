#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int x, y, z;
    cin >> x >> y >> z;
    int dp[2][n + 1];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j <= n; j++){
            int cur;
            switch(i){
                case 0:
                    cur = x;
                break;
                case 1:
                    cur = y;
                break;
                case 2:
                    cur = z;
                break;
            }
            if(j == 0)dp[i%2][j] = 0;
            else if(i == 0){
                if(j >= cur){
                    if(j == cur || dp[i%2][j - cur] > 0)dp[i%2][j] = 1 + dp[i%2][j - cur];
                    else dp[i % 2][j] = 0;
                }else dp[i%2][j] = 0;
            }else{
                if(j >= cur){
                    if(j == cur || dp[i%2][j - cur] > 0)dp[i%2][j] = max(1 + dp[i%2][j - cur], dp[(i - 1)%2][j]);
                    else if(dp[(i - 1)%2][j] > 0)dp[i%2][j] = dp[(i - 1)%2][j];
                    else dp[i%2][j] = 0;
                }else dp[i%2][j] = dp[(i - 1)%2][j];
            }
            //cout << dp[i % 2][j] << " ";
        }
        //cout << endl;
    }
    cout << dp[0][n];
    return 0;
}