#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    vector <int> psa1, psa2;
    cin  >> n;
    psa1.push_back(0);
    psa2.push_back(0);
    int k = 0;
    for(int i = 0; i < n; i++){
        int d;
        cin >> d;
        psa1.push_back(d + psa1[i]);
    }
    for(int i = 0; i < n; i++){
        int d;
        cin >> d;
        psa2.push_back(d + psa2[i]);
    }
    for(int i = 0; i <= n; i++){
        if(psa1[i] == psa2[i])k = i;
    }
    cout << k << endl;
    return 0;
}