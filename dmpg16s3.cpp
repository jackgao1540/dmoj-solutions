#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m, r;
  cin >> n >> r >> m;
  bool stops[100001] = {0};
  for(int i = 0; i < r; i++){
    int d;
    cin >> d;
    stops[d] = true;
  }
  int numR = 0;
  vector <int> passengers;
  for(int i = 0; i < m; i++){
    int d;
    cin >> d;
    if(stops[d])numR++;
  }
  //minimize the difference between m - numR and numR 
  int other = m - numR;
  if(other == numR){
    cout << (numR + 1) * numR << endl;
  }else if(other > numR){
    cout << (other + 1) * other / 2 + numR * (numR + 1) / 2 << endl;
  }else{
    if(m % 2 == 0)cout << (m / 2 + 1) * (m / 2) << endl;
    else{
      cout << (m / 2) * (m / 2 + 1) / 2 + (m / 2 + 1) * (m / 2 + 2) / 2 << endl;
    }
  }
}