#include <iostream>
#include <string>
#include <vector>

using namespace std;

int c[3001][3001] = {0}, b[3001][3001] = {0};

//1 is left, 2 is diagonal, 3 is up

void printLCS(string x, int i, int j){
  if(i == 0 || j == 0)return;
  if(b[i][j] == 2){
    printLCS(x, i - 1, j - 1);
    cout << x[i - 1];
  }else if(b[i][j] == 3){
    printLCS(x, i - 1, j);
  }else printLCS(x, i, j - 1);
}

void calcLCS(string x, string y){
  int m = x.length(), n = y.length();
  for(int i = 1; i <= m; i++){
    for(int j = 1; j <= n; j++){
      if(x[i - 1] == y[j - 1]){
        c[i][j] = c[i - 1][j - 1] + 1;
        b[i][j] = 2;
      }else{
        if(c[i - 1][j] >= c[i][j - 1]){
          c[i][j] = c[i - 1][j];
          b[i][j] = 3;
        }else{
          c[i][j] = c[i][j - 1];
          b[i][j] = 1;
        }
      }
    }
  }
}

int main(){
  string x, y;
  cin >> x >> y;
  calcLCS(x, y);
  int lcsLength = c[x.size()][y.size()];
 // cout << lcsLength;
  printLCS(x, x.size(), y.size());
}