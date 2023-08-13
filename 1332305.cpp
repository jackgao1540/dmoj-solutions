#include <bits/stdc++.h>

using namespace std;

int w, h, n;
int grid[251][251] = {0};
long psa[251][251] = {0};



int main() {
  cin >> w >> h >> n;
  for(int i = 1; i <= h; i++){
    for(int j = 1; j <= w; j++){
      cin >> grid[i][j];
      psa[i][j] = grid[i][j] - psa[i - 1][j - 1] + psa[i - 1][j] + psa[i][j - 1];
      //cout << psa[i][j] << ' ';
    }
    //cout << endl;
  }
  //cout << endl;

  //brute force
  long maxScore = 0;
  for(int i = 1; i <= h; i++){
    for(int j = 1; j <= w; j++){
      for(int width = 1; width + j - 1 <= w; width++){
        int height = n / width;
        int a = i, b = j, c = min(i + height - 1, h), d = width + j - 1;
        int area = psa[c][d] - psa[c][b - 1] - psa[a - 1][d] + psa[a - 1][b - 1];
        if(area > maxScore)maxScore = area; 
      }
    }
  }
  cout << maxScore;
}