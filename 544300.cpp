#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c;
    cin>>a>>b>>c;
    if((a>b && b>c)||(c>b && b>a)) cout << b;
    if((b>c && c>a)||(a>c && c>b)) cout << c;
    if((c>a && a>b)||(b>a && a>c)) cout << a;
    return 0;
}