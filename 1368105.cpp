#include <bits/stdc++.h>

using namespace std;

int main() {
    int earliest[1000002] = {0};
    long psa = 0;
    int n, k;
    cin >> n >> k;
    int bestDist = 0;
    earliest[0] = 0;
    for(int i = 1; i <= n; i++){
      int d;
      cin >> d;
      psa += d%k;
      psa %= k;
      if(earliest[psa] == 0 && psa != 0)earliest[psa] = i;
      else{
        bestDist = max(i - earliest[psa], bestDist);
      }
    }
    cout << bestDist;
    return 0;
}