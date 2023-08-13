#include <bits/stdc++.h>

using namespace std;

struct win {int x1, x2, y1, y2, v;} w[1001];

int n, t, cntx, cnty, dif[2002][2002]; 
map<int, int> cx, cy; 
vector<int> rx, ry; 
long long ans=0;

int main(){
    scanf("%d %d", &n, &t);
    for(int i=1; i<=n; i++){
        scanf("%d %d %d %d %d", &w[i].x1, &w[i].y1, &w[i].x2, &w[i].y2, &w[i].v);
        cx[w[i].x1]=cx[w[i].x2]=0; cy[w[i].y1]=cy[w[i].y2]=0;
    }
    cntx=1; cnty=1;
    for(auto &it: cx){ it.second = cntx++; rx.push_back(it.first); }
    for(auto &it: cy){ it.second = cnty++; ry.push_back(it.first); }
    for(int i=1; i<=n; i++){
        dif[ cx[w[i].x1] ][ cy[w[i].y1] ] += w[i].v;
        dif[ cx[w[i].x2] ][ cy[w[i].y2] ] += w[i].v;
        dif[ cx[w[i].x1] ][ cy[w[i].y2] ] -= w[i].v;
        dif[ cx[w[i].x2] ][ cy[w[i].y1] ] -= w[i].v;
    }
    for(int i=1; i<cntx; i++){
        for(int j=1; j<cnty; j++){
            dif[i][j] += dif[i-1][j] + dif[i][j-1] - dif[i-1][j-1];
            if(dif[i][j] >= t) ans += 1LL*(rx[i]-rx[i-1])*(ry[j]-ry[j-1]);
        }
    }
    printf("%lld\n", ans);
}