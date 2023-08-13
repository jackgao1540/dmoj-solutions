#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, t;
    cin >> a >> b >> t;
    double ti = (double)t + 0.5;
    ti /= (double)b;
    int times = (int)ti;
    cout << a * times << endl;
    return 0;
}