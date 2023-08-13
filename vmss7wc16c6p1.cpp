#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector <int> x, y;
    for(int  i = 0, a, b; i < n; i++){
        scanf("%d%d", &a, &b);
        x.push_back(a);
        y.push_back(b);
    }
    long sum = 0;
    for(int i = 0; i < n; i++){
        sum += x[i] * y[(i + 1)%n] - y[i] * x[(i + 1)%n];
    }
    if(sum < 0)sum = - sum;
    printf("%d\n", sum/2 + sum%2);
    return 0;
}