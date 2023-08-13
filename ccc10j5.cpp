#include <iostream>
#include <list>

using namespace std;

int xO, yO, xo, yo;

int bfs(int x, int y){
  list <pair <pair <int, int>, int>> qu;
  pair <int, int> t;
  t.first = x;
  t.second = y;
  pair <pair <int, int>, int> agsf;
  agsf.first = t;
  agsf.second = 0;
  qu.push_back(agsf);
  while(!qu.empty()){
    pair <pair <int, int>, int> cur;
    cur = qu.front();
    qu.pop_front();
    if(cur.first.first == xo && cur.first.second == yo){
      return cur.second;
    }
    //8 possible moves
    //up
    pair <int, int> a;
    pair <pair <int, int> , int> b;
    if(cur.first.second  <= 6){
      //can move up
      if(cur.first.first > 1){
        a.first = cur.first.first - 1;
        a.second = cur.first.second + 2;
        b.first = a;
        b.second = cur.second + 1;
        qu.push_back(b);
      }
      if(cur.first.first < 8){
        a.first = cur.first.first + 1;
        a.second = cur.first.second + 2;
        b.first = a;
        b.second = cur.second + 1;
        qu.push_back(b);
      }
    }
    if(cur.first.second >= 3){
      //can move down
      if(cur.first.first > 1){
        a.first = cur.first.first - 1;
        a.second = cur.first.second - 2;
        b.first = a;
        b.second = cur.second + 1;
        qu.push_back(b);
      }
      if(cur.first.first < 8){
        a.first = cur.first.first + 1;
        a.second = cur.first.second - 2;
        b.first = a;
        b.second = cur.second + 1;
        qu.push_back(b);
      }
    }
    if(cur.first.first <= 6){
      // can move right
      if(cur.first.second > 1){
        a.first = cur.first.first + 2;
        a.second = cur.first.second - 1;
        b.first = a;
        b.second = cur.second + 1;
        qu.push_back(b);  
      }
      if(cur.first.second < 8){
        a.first = cur.first.first + 2;
        a.second = cur.first.second + 1;
        b.first = a;
        b.second = cur.second + 1;
        qu.push_back(b);  
      }
    }
    if(cur.first.first >= 3){
      //can move left
       if(cur.first.second > 1){
        a.first = cur.first.first - 2;
        a.second = cur.first.second - 1;
        b.first = a;
        b.second = cur.second + 1;
        qu.push_back(b);  
      }
      if(cur.first.second < 8){
        a.first = cur.first.first - 2;
        a.second = cur.first.second + 1;
        b.first = a;
        b.second = cur.second + 1;
        qu.push_back(b);  
      }
    }
  }
  return -1;
}

int main() {
  cin >> xO >> yO >> xo >> yo;
  cout << bfs(xO, yO);
}