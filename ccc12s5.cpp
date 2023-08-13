#include <iostream>

/*
3
4
3
1 4
2 3
2 1
*/

using namespace std;

int r, c, numCats;
int cage[25][25] = { 0 }, dp[25][25] = { 0 };

int main() {
  cin >> r >> c >> numCats;
  int a, b;
  for(int i = 0; i < numCats; i++){
    cin >> a >> b;
    cage[a - 1][b - 1] = 1;
  }
  dp[0][0] = 1;
  for(int i = 0; i < r; i++){   
    for(int j = 0; j < c; j++){
      if(cage[i][j])continue;
      dp[i][j] += (j > 0 ? dp[i][j - 1] : 0);
      dp[i][j] += (i > 0 ? dp[i - 1][j] : 0);
    }
    cout << endl;
  }
  //for(int i = 0; i < r; i++){
   // for(int j = 0; j < c; j++)cout << dp[i][j] << " ";
   // cout << endl;
 // }
  cout << dp[r - 1][c - 1];
  return 0;
}