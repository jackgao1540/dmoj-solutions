#include <bits/stdc++.h>

using namespace std;

int rows, columns;
int grid[35][50] = {0};

int floodFill(int row, int col){
  int x = 0;
  if(row < 0 || row > rows - 1 || col < 0 || col > columns - 1 || grid[row][col] == -1)return 0;
  if(grid[row][col] == 1){
    x += 1;
  }
  grid[row][col] = -1;
  int a, b, c, d;
  a = floodFill(row + 1, col); 
  b = floodFill(row - 1, col); 
  c = floodFill(row, col + 1); 
  d = floodFill(row, col - 1); 
  return ((a + b + c + d + x) > 0? 1 : 0);
}

int main() {
  cin >> rows >> columns;
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < columns; j++){
      char c;
      cin >> c;
      if(c == '.')grid[i][j] = 0;
      else if(c == 'M')grid[i][j] = 1;
      else grid[i][j] = -1;
      //cout << grid[i][j] << " ";
    }
    //cout << endl;
  }
  int count = 0;
  for(int i = 1; i < rows - 1; i++){
    for(int j = 1; j < columns - 1; j++){
      if(grid[i][j] > -1)count += floodFill(i, j);
    }
  }
  cout << count;
}