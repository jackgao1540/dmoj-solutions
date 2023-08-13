#include <bits/stdc++.h>

using namespace std;

#define MM 10005
int n, f[MM];

int bfs(int cur, int dest){
    list <int> qu;
    list <int> dist;
    bool visited[MM] = {0};
    visited[cur] = true;
    qu.push_back(f[cur]);
    dist.push_back(0);
    while(!qu.empty()){
        int c = qu.front(), cd = dist.front(); qu.pop_front(); dist.pop_front();
        if(visited[c])continue;
        visited[c] = true;
        if(c == dest)return cd;
        qu.push_back(f[c]);
        dist.push_back(cd + 1);
    }
    return -1;
}

int main() {
    scanf("%d", &n);
    for(int i = 0, x, y; i < n; i++){
        scanf("%d%d", &x, &y);
        f[x] = y;
    }
    int x, y;
    scanf("%d%d", &x, &y);
    while(x != 0){
        int a = bfs(x, y), b = bfs(y, x);
        if(a>= 0 && b >= 0)cout << "Yes " << a << endl;
        else cout << "No" << endl;
        scanf("%d%d", &x, &y);
    }
    return 0;
}