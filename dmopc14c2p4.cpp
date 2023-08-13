#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int num[1000001] = {0};
    cin >> n;
    for(int i = 1; i <= n; i++){
        int d;
        cin >> d;
        num[i] = d + num[i - 1];
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        cout << num[b + 1] - num[a] << endl;
    }
    return 0;
}