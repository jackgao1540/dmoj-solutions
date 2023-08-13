#include <bits/stdc++.h>

using namespace std;

int main() {
    int m;
    int y;
    cin>>m>>y;
    if(m<y) {
        int temp = y;
        y = m;
        m = temp;
    }
    cout<< 2*m - y;
    return 0;
}