#include <bits/stdc++.h>

using namespace std;

bool checkBit(int n, int pos){
  return (n & (1 << pos));
}

int main() {
    int n, m, k, numP = 0, numB = 0;
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++){
        if(checkBit(n, i) ^ checkBit(m, i))numB++;
        else numP++;
    }
    cout << numB << ' ' << numP << endl;
    return 0;
}