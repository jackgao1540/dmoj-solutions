#include <iostream>

using namespace std;

int bit[1100][1100], op, x1, y1, x2, y2, v, n;

void upd(int x, int y, int val){
  for(int i = x; i <= n; i+=i&-i){
    for(int j = y; j <= n; j+=j&-j){
      bit[i][j] += val;
    }
  }
}
int query(int x, int y){
  int sum = 0;
  for(int i = x; i > 0; i-=i&-i){
    for(int j = y; j > 0; j-=j&-j){
      sum += bit[i][j];
    }
  }
  return sum;
}
int query(int x1, int y1, int x2, int y2){
  return query(x2, y2) - query(x1, y2) - query(x2, y1) + query(x1, y1);
}
int main() {
  while(true){
    cin >> op;
    if(op == 3)break;
    if(op == 0)cin >> n;
    else if(op == 1){
      cin >> x1 >> y1 >> v;
      upd(x1 + 1, y1 + 1, v);
    }else if(op == 2){
      cin >> x1 >> y1 >> x2 >> y2;
      cout << query(x1, y1, x2 + 1, y2 + 1) << endl;
    }
  }
}