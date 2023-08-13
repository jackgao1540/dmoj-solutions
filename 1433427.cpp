#include <bits/stdc++.h>
using namespace std;
int N, h[17], dp[1<<15];
bool check(int mask){
    vector<int> t;
    for(int i=0; i<N; i++)
        if(mask & (1<<i)) t.push_back(h[i]);
    if(t.size() == 1) return true;
    bool inc = true, dec = true;
    for(int i=1; i<t.size(); i++){
        if( t[i] > t[i-1] ) dec = false;
        if( t[i] < t[i-1] ) inc = false;
    }
    return inc || dec;
}
int solve(int mask){
    if(dp[mask] != -1) return dp[mask];
    if( check(mask) ) return dp[mask] = 1;
    int ret = 0;
    for(int i=0; i<N; i++)
        if(mask & (1<<i))  ret |= solve(mask ^ (1<<i));
    return dp[mask] = !ret;
}
int main(){
    for(int t=1; t<=5; t++){
        for(int k=1; k<=3; k++){
            scanf("%d", &N);  memset(dp, -1, sizeof(dp));
            for(int i=0; i<N; i++) scanf("%d", &h[i]);
            if( solve((1<<N)-1) ) printf("B");
            else printf("A");
        }
        printf("\n");
    }
}