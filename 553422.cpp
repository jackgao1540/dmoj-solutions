#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;
    if(n == 1 || n == 10) cout<< 1; else 
    if(n == 2 || n == 3 || n == 7 || n == 8) cout<<2; else 
    if( n == 4 || n == 5 || n == 6) cout<<3; else cout<< 1 ;
    return 0;
}