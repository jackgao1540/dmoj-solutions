#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  vector <int> numbers, lMax, rMax, lVal, rVal;
  int maxx = 0;
  for(int i = 0; i < n; i++){
    int d;
    cin >> d;
    numbers.push_back(d);
    rMax.push_back(0);
    rVal.push_back(0);
    //do lMax and lVal
    if(i == 0){
      lMax.push_back(d);
      lVal.push_back(1);
      maxx = d;
    }else{
      if(d > maxx){
        maxx = d;
        lMax.push_back(maxx);
        lVal.push_back(1);
      }else if(d == maxx){
        lMax.push_back(d);
        lVal.push_back(lVal[i - 1] + 1);
      }else{
        lMax.push_back(lMax[i - 1]);
        lVal.push_back(lVal[i - 1]);
      }
    }
    //cout << "(" << lMax[i] << ", " << lVal[i] << "), ";
    //cout << numbers[i] << ' ';
  }
  maxx =0;
  //now do rMax and rVal
  for(int i = n - 1; i > -1; i--){
    int cur = numbers[i];
    if(i == n - 1){
      rMax[i] = cur;
      rVal[i] = 1;
      maxx = cur;
    }else{
      if(cur > maxx){
        maxx = cur;
        rMax[i] = maxx;
        rVal[i] = 1;
      }else if(cur == maxx){
        rMax[i] = cur;
        rVal[i] = rVal[i + 1] + 1;
      }else{
        rMax[i] = rMax[i + 1];
        rVal[i] = rVal[i + 1];
      }
    }
   
  }
  //test
  //for(int  i = 0; i < n; i++){
  //   cout << "(" << rMax[i] << ", " << rVal[i] << "), ";
  //}
  for(int k = 0; k < q; k++){
    int a, b;
    cin >> a >> b;
    int x = lMax[a - 2], y = rMax[b];
    if(x > y){
      cout << x << ' ' << lVal[a - 2] << endl;
    }else if(x == y){
      cout << x << ' ' << lVal[a - 2] + rVal[b] << endl;
    }else cout << y << ' ' << rVal[b] << endl;
  }
}