#include <bits/stdc++.h>

using namespace std;

int main() {
    int x, y;
    cin>>x>>y;
    if(x < 2){
        cout<<"Before";
    }else if(x > 2){
        cout<<"After";
    }else{
        if(y < 18){
            cout<<"Before";
        }else if(y > 18){
            cout<<"After";
        }else{
            cout<<"Special";
        }
    }
    return 0;
}