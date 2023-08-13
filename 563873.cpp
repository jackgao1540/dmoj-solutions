#include <bits/stdc++.h>

using namespace std;

int main() {
    int x, y;
    cin>>x>>y;
    if(x < 0){
        //quadrants 2 and 3
        if(y < 0){
            //quadrant 3
            cout<<3;
        }else{
            //quandrant 2
            cout<<2;
        }
    }else{
        //quadrants 1 and 4
        if(y < 0){
        //quadrant 4
        cout<<4;
        }else{
            //quadrant 1
            cout<<1;
        }
    }
    return 0;
}