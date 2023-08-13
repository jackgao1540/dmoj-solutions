#include <bits/stdc++.h>

using namespace std;

int main() {
    int x;
    cin >> x;
    for(int i = 0; i < x; i++){
        int a, b;
        cin >> a >> b;
        for(int i = 0; i < (b > 0 ? b : -b); i++){
            if(b < 0)a -= 1;
            else a += 1;
        }
        cout << a << endl;
    }
    return 0;
}