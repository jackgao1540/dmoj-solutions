#include <iostream>

using namespace std;

int abs(int a){
  if(a < 0)return -a;
  else return a;
}

int main() {
  //A -> 1
  // . -> 0
  int total = 0;
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      char c;
      cin >> c;
      if(c == '.'){
        //total += abs(3 - i) + abs(3 - j);
        continue;
      }else{
        int val = (int)c;
        val -= 'A';
        int x, y;
        x = val / 4;
        y = val % 4;
        total += abs(x - i) + abs(y - j);
      }
    }
  }
  cout << total;
}