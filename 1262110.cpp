#include <iostream>

using namespace std;

int main(){
  int n;
  cin >> n;
  int box[1010][1010] = {0};
  int maxR, maxC, minR, minC;
  int found = 0;
  int size = 0;
  int realSize = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> box[i][j];
    }
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(box[i][j] != i*n + j + 1){
        found = 1;
        int x = i + 1, y = j + 1;
        size = 1;
        while(x < n && y < n){
          if(box[x][y] != (x)*n + y + 1){
            x++;
            y++;
            size++;
            realSize = size;
          }else{
            x++;
            y++;
            size++;
          }
        }
        break;
      }
    }
    if(found == 1)break;
  }
  cout << realSize << endl;
}