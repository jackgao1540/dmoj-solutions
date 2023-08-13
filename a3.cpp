#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    int k;
    cin >> t;
    while(t > 0){
        cin >> k;
        for(long i = k+1; ;i++){
            if(i*i*i%1000 != 888)continue;
            else {
                cout << i << endl;
                break;
            }
        }
        t--;
    }
    return 0;
}