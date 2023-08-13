#include <iostream>
#include <list>
#include <string>
/*
5
 1
 1
 0
 1
 1
 ///////
 10
 1 1 0 0 1 0 0 1 1 1
*/
using namespace std;

unsigned long long int bulbs = 0;
bool searched[33554433] = {0};
int n;

bool findBit(unsigned long long int d, int pos){
  return ((d & (1 << pos)) > 0);
}

pair <int, int> findRange(unsigned long long int num, int pos){
  pair <int, int> t;
  t.first = pos;
  t.second= pos;
  while(findBit(num, t.first)){
    //find the left side range
    t.first -= 1;
  }
  while(findBit(num, t.second)){
    t.second += 1;
  }
  return t;
}

unsigned long long int setBits(unsigned long long int d, int pos){
  //if the adjacent bit is a 1, set to zero, or else don't continue along that path
  //only if there are four or more
  unsigned long long int newD = d;
  newD |= (1 << pos);
  //cout << newD << endl;
  pair <int, int> range = findRange(newD, pos);
  range.second -= 1;
  range.first += 1;
  //cout << "    " << range.second << ' ' << range.first << endl;
  if(range.second - range.first >= 3){
    //set all to 0
    for(int i = range.first; i <= range.second; i++){
      newD ^= (1 << i);
    }
    return newD;
  }else return newD;
}

int bfs(unsigned long long int b){
  list <pair <unsigned long long int, int>> qu;
  pair <unsigned long long int, int> t;
  t.first = b;
  t.second = 0;
  qu.push_back(t);
  while(!qu.empty()){
    t = qu.front();
    qu.pop_front();
    //test
    //cout << toBin(t.first) << endl;
    if(searched[t.first])continue;
    searched[t.first] = 1;
    if(t.first == 0)return t.second;
    //find all zeroes in t, and add to queue
    for(int i = 0; i < n; i++){
      if((t.first & (1 << i)) == 0){
        //can set to 1
        unsigned long long int newT;
        newT = setBits(t.first, i);
        //cout << "     " << toBin(newT) << endl;
        pair <unsigned long long int , int> newt;
        newt.first = newT;
        newt.second = t.second + 1;
        qu.push_back(newt);
      }
    }
  } 
  return -1;
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++){
    int t;
    cin >> t;
    bulbs |= (t << i);
  }
  cout << bfs(bulbs);
  return 0;
}