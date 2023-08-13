#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

long double dist(pair <int, int> a, pair <int, int> b){
  return sqrt((a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second));
}

long long abs(int a, int b){
  return a - b < 0 ? b - a : a - b;
}

int main() {
  int x, y, x1, y1, x2, y2;
  cin >> x >> y >> x1 >> y1 >> x2 >> y2;
  cout << fixed;
  cout << setprecision(3);
  long double mrl;
  //x1 < x2, y1 < y2
  pair <int, int> bl, br, tl, tr, goat;
  bl = make_pair(x1, y1);
  tl = make_pair(x1, y2);
  br = make_pair(x2, y1);
  tr = make_pair(x2, y2);
  goat = make_pair(x, y);
  if(x < x1 && y < y1){
    //take the distance to bl
    //cout << "bl" << endl;
    mrl = dist(goat, bl);
  }else if(x > x2 && y < y1){
    //take br
    //cout << "br" << endl;
    mrl = dist(goat, br);
  }else if(x > x2 && y > y2){
    //take tr
    //cout << "tr" << endl;
    mrl = dist(goat, tr);
  }else if(x < x1 && y > y2){
    //take tl
    //cout << "tl" << endl;
    mrl = dist(goat, tl);
  }else if(x < x1){
    //take x1 - x
    //cout << "left side" << endl;
    mrl = abs(x1, x);
  }else if(y < y1){
    //take y1 - y
    //cout << "bottom side" << endl;
    mrl = abs(y1, y);
  }else if(y > y2){
    //take y - y2
    //cout << "top side" << endl;
    mrl = abs(y2, y);
  }else if(x > x2){
    //take x - x2
    //cout << "right side" << endl;
    mrl = abs(x2, x);
  }
  cout << mrl << endl;
}