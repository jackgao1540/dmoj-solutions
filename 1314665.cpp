#include <iostream>
#include <string>
#include <vector>

using namespace std;

int c[3001][3001] = {0};

//1 is left, 2 is diagonal, 3 is up

void calcLCS(string x, string y){
  int m = x.length(), n = y.length();
  for(int i = 1; i <= m; i++){
    for(int j = 1; j <= n; j++){
      if(x[i - 1] == y[j - 1]){
        c[i][j] = c[i - 1][j - 1] + 1;
      }else{
        if(c[i - 1][j] >= c[i][j - 1]){
          c[i][j] = c[i - 1][j];
        }else{
          c[i][j] = c[i][j - 1];
        }
      }
    }
  }
}

int main(){
  string x, y;
  cin >> x;
  y =  "abcdefghijklmnopqrstuvwxyz";
  calcLCS(x, y);
  int lcsLength = c[x.size()][y.size()];
  cout << 26 - lcsLength << endl;
}