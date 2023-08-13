#include <bits/stdc++.h>

using namespace std;

int main() {
    int x, y;
    cin>>x>>y;
    string adj[x], noun[y];
    for(int r = 0; r < x; r++){
        cin>>adj[r];
    }
    for(int r = 0; r < y; r++){
        cin>>noun[r];
    }
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            cout<<adj[i]<<" as "<<noun[j]<<endl;
        }
    }
    return 0;
}