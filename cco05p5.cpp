#include <bits/stdc++.h>

using namespace std;

const int MM = 2e4 + 3;
int N, l[MM], r[MM], dp[MM][2];

int main() {
    cin >> N;
    for(int i = 1; i <= N; i++)cin >> l[i] >> r[i];
    dp[1][0] = r[1] - 1 + r[1] - l[1];
    dp[1][1] = r[1] - 1;
    for(int i = 2; i <= N; i++){
        dp[i][0] = min(dp[i - 1][0] + abs(r[i] - l[i - 1]), dp[i - 1][1] + abs(r[i] - r[i - 1])) + r[i] - l[i];
        dp[i][1] = min(dp[i - 1][0] + abs(l[i] - l[i - 1]), dp[i - 1][1] + abs(l[i] - r[i - 1])) + r[i] - l[i];
    }
    cout << min(dp[N][0] + N - l[N], dp[N][1] + N - r[N]) + N - 1;
    return 0;
}