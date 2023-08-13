#include <bits/stdc++.h>

using namespace std;

int N;
double v;

int main() {
  for(int t = 0; t < 10; t++){
     scanf("%d", &N);
     vector <double> pt[1000001];
     int mx = 0;
     for(int i = 1, d; i <= N; i++){
       scanf("%d %lf", &d, &v);
       pt[d].push_back(v);
       mx = max(mx, d);
     }
     priority_queue <double> q;
     double ans = 0.0;
     for(int i = mx; i >= 1; i--){
       for(double v: pt[i])q.push(v);
       if(!q.empty()){
         ans += q.top();
         q.pop();
       }
     }
     cout << fixed;
     cout << setprecision(4);
     cout << ans << endl;
  }
}