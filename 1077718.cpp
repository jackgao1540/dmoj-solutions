#include <bits/stdc++.h>

using namespace std;
    int n, h;
int field[1500][1500];
int searched[1500][1500] = {0};

int elDiff(int x, int y, int a, int b){
  int diff = field[a][b] - field[x][y];
  return sqrt(diff*diff);
}

int bfs(int x, int y){
    list <pair <int, int>> qu;
    pair <int, int> temp;
    temp.first = x;
    temp.second = y;
    qu.push_back(temp);
    while(!qu.empty()){
        temp = qu.front();
        qu.pop_front();
        int r = temp.first, c = temp.second;
        if(searched[r][c])continue;
        searched[r][c] = 1;
        if(r == n - 1 && c == n - 1)return 1;
        //spread
        if(r > 0 && elDiff(r, c, r - 1, c) <= h){
            temp.first = r - 1;
            temp.second = c;
            qu.push_back(temp);
        }
        if(r < n - 1 && elDiff(r, c, r + 1, c) <= h){
            temp.first = r + 1;
            temp.second = c;
            qu.push_back(temp);
        }
        if(c > 0 && elDiff(r, c, r, c - 1) <= h){
            temp.first = r;
            temp.second = c - 1;
            qu.push_back(temp);
        }
        if(c < n - 1 && elDiff(r, c, r, c + 1) <= h){
            temp.first = r;
            temp.second = c + 1;
            qu.push_back(temp);
        }
    }
    return 0;
}

int main() {
    cin >> n >> h;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> field[i][j];
        }
    }
    if(bfs(0, 0))cout << "yes";
    else cout << "no";
    return 0;
}