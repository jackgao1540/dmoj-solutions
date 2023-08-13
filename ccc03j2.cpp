#include <bits/stdc++.h>

using namespace std;

int main() {
    int c;
    cin >> c;
    while(c != 0){
        int d = sqrt(c);
        for(int i = d; i > 0; i--){
            if(c % i == 0){
                cout << "Minimum perimeter is " << (2 * d + 2 * (c / d)) << " with dimensions " << d << " x " << c/d << endl;            
                break;
            }
        }
        cin >> c;
    }
    return 0;
}