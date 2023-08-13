#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = 0;
    for(int i = n; i * i >= n; i--){
        if(n % i != 0)continue;
        ans = max(ans, n/i + i);
    }
    cout << 2 * ans << endl;
    return 0;
}