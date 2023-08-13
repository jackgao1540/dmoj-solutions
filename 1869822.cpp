#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, K, M, lo, hi, ans;
ll check(ll mid){
    ll tot = 0, days = 0;
    while(days < K && tot < N){
        ll y = (N - tot)/mid;
        if (y <= M) return tot + (K-days)*M;
        ll tmp = min(K-days, (N - mid*y - tot)/y + 1);
        tot += tmp*y; days += tmp;
    }
    return tot;
}
int main(){
    cin >> N >> K >> M;
    lo = 1; hi = N;
    while(lo <= hi){
        ll mid = (lo + hi)/2;
        if(check(mid) >= N){ ans = mid; lo = mid+1; }
        else hi = mid-1;
    }
    cout << ans << "\n";
}