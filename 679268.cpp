#include <bits/stdc++.h>

using namespace std;

int main() {
    string a, b, c;
    a = "TroyMartian";
    b = "VladSaturnian";
    c = "GraemeMercurian";
    int d,e;
    cin>>d>>e;
    if(d >= 3 && e <= 4){
        cout<<a<<endl;
    }
    if(d <= 6 && e >= 2){
        cout<<b<<endl;
    }
    if(d <= 2 && e <= 3)cout<<c;
    return 0;
}