#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c, d;
    cin>>a;
    cin>>b;
    cin>>c;
    cin>>d;
    if(a<b && b <c && c<d ) {
        cout<<"Fish Rising";
    }else if(a==b && b==c && c==d){
        cout<<"Fish At Constant Depth";
    }else if (a > b && b > c && c> d){
        cout<<"Fish Diving";
    }else{
        cout<<"No Fish";
    }
    return 0;
}