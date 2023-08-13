#include <bits/stdc++.h>

using namespace std;

int main() {
    int m, n, u, f, d;
    scanf("%d%d%d%d%d", &m, &n, &u, &f, &d);
    char c;
    int score = 0;
    for(int i = 0; i < n; i++){
        cin >> c;
        if(c == 'f'){
            score += 2*f;
        }else score += u + d;
        if(score > m){cout << i << endl;return 0;}
    }
    cout << n << endl;
    return 0;
}