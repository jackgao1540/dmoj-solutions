#include <bits/stdc++.h>

using namespace std;

int N;

int main() {
     scanf("%d", &N);
     vector <int> pt[1000001];
     int mx = 0;
     for(int i = 1, d, v; i <= N; i++){
       cin >> d >> v;
       pt[d].push_back(v);
       mx = max(mx, d);
     }
     priority_queue <int> q;
     unsigned long long ans = 0;
     for(int i = mx; i >= 1; i--){
       for(int v: pt[i])q.push(v);
       if(!q.empty()){
         ans += q.top();
         q.pop();
       }
     }
     cout << ans << endl;
}