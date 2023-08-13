#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << min(c, (int)(b/a)) << endl;
    return 0;
}