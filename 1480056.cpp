#include <bits/stdc++.h>

using namespace std;

int main() {
  int startD, startH, startM;
  startD = startH = startM = 11;
  int endD, endH, endM;
  cin >> endD >> endH >> endM;
  if(endD < startD)cout << -1 << endl;
  else if(endD == startD){
    if(endH < startH)cout << -1 << endl;
    else if(endH == startH){
      if(endM < startM)cout << -1 << endl;
      else if(endM == startM)cout << 0 << endl;
      else cout << endM - startM << endl;
    }else{
      cout << endM + 60 - startM + (endH - startH - 1) * 60;
    }
  }else{
    cout << 24 * 60 * (endD - startD - 1) + endH * 60 + endM + 60 - startM + (24 - startH - 1) * 60 << endl;
  }
}