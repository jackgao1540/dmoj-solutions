#include <bits/stdc++.h>

using namespace std;

int main() { 
    string a, b;
    cin >> a >> b;
    long ans = 0;
    for(int i = 0; i < a.size(); i++){
      for(int j = 0; j < b.size(); j++){
        ans += (a[i] - '0') * (b[j] - '0');
      }
    }
    cout << ans << endl;
    return 0;
}