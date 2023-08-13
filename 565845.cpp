#include <bits/stdc++.h>

using namespace std;

int d(int t, int h){
    return -6*(t*t*t*t) + (h*t*t*t) + (2*t*t) + t;
}

int main() {
    int h, m;
    cin>>h>>m;
    for(int i = 1; i < m+1; i++){
        if(d(i, h)<= 0){
            cout<<"The balloon first touches ground at hour:"<<endl<<i;
            break;
        }else if(i == m){
            cout<<"The balloon does not touch ground in the given time.";
            break;
        }
    }
    return 0;
}