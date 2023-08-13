#include <bits/stdc++.h>

using namespace std;

int main() {
    int l1, l2, n;
    cin>>l1>>l2;
    n = l1 - l2;
    int c = 3;
    while(l2 >= n){
        l1 = l2;
        l2 = n;
        n = l1 - l2;
        c++;
    }
    cout<<c;
    return 0;
}