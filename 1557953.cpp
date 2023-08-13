#include <bits/stdc++.h>

using namespace std;

int maxPowerof2(int n){
  int p = (int)log2(n);
  return (int)pow(2, p);
}

int recur(int rows, int cols){
  int ans = 0;
  //take maximum out of top left
  if(rows == 0 || cols == 0)return 0;
  if(rows == 1 && cols == 1)return 1;
  else if(rows == 1)return cols;
  else if(cols == 1)return rows;
  int maxSide = maxPowerof2(min(rows, cols));
  //find maximum amount of this square that fits
  return ((int)(rows/maxSide))*((int)(cols/maxSide)) + recur(rows%maxSide, cols) + recur(rows, cols%maxSide) - recur(rows%maxSide, cols%maxSide);
}

int main() {
  for(int k = 0; k < 5; k++){
    int n, m;
    scanf("%d %d", &n, &m);
    cout << recur(n, m) << endl;
  }
}