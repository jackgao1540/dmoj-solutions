#include <bits/stdc++.h>

using namespace std;

int main() {
  for(int j = 0; j < 5; j++){
    int r, c, ro;
    cin >> r >> c >> ro;
    unsigned int tot = r * c;
    set <int> takenRows, takenCols;
    for(int i = 0; i < ro; i++){
        int a, b;
        cin >> a >> b;
        takenRows.insert(a);
        takenCols.insert(b);
    }
    int tR = takenRows.size(), tC = takenCols.size();
    tot -= (tR * c + tC * r - tR * tC);
    cout << tot << endl;
  }
    return 0;
}