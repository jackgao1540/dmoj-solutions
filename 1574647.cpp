#include <bits/stdc++.h>

using namespace std;

int n, m, arr[3005], bagOfPies[105], dp[3005][2][105][105];

int recur(int cur, int t, int l, int r)
{
    int& tmp = dp[cur][t][l][r];
    //if dp[cur][t][l][r] has already been calculated then return the answer
    if(tmp != -1)return tmp;
    //if it's the end of the bag 
    if(cur == n + 1){
        //if there are still elements left in the bag
        if(l <= r){
            //if taken last time 
            if(t)return tmp = bagOfPies[r] + recur(cur, 0, l, r - 1);
            return tmp = recur(cur, 1, l + 1, r);
        }
        return tmp = 0;
    }
    //if taken last time 
    if(t){
        tmp = max(recur(cur, 0, l, r), arr[cur] + recur(cur + 1, 0, l, r));
        if(l <= r)tmp = max(tmp, bagOfPies[r] + recur(cur, 0, l, r - 1));
    }
    else{
        tmp=recur(cur + 1, 1, l, r);
        if(l <= r)tmp = max(tmp, recur(cur, 1, l + 1, r));
    }
    return tmp;
}

int main(){
    memset(dp, -1, sizeof dp);
    cin >> n;
    for(int i = 1; i <= n; i++)cin>>arr[i];
    cin >> m;
    for(int i = 1; i <= m; i++)cin >> bagOfPies[i];
    sort(bagOfPies + 1, bagOfPies + 1 + m);
    cout << recur(1, 1, 1, m) << endl;
}