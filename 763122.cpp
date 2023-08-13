#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int maxL, maxR, maxU, maxD;
    int numPoints;
    cin>>numPoints;
    maxL = LLONG_MAX;
    maxR = LLONG_MIN;
    maxU = LLONG_MIN;
    maxD = LLONG_MAX;
    for(int i = 0; i < numPoints; i++){
        int a, b;
        cin>>a>>b;
        if(a > maxR) maxR = a;
        if(a < maxL) maxL = a;
        if(b > maxU) maxU = b;
        if(b < maxD) maxD = b;
    }
    cout<<(maxR - maxL) * (maxU - maxD);
    return 0;
}