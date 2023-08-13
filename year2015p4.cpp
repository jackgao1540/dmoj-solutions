#include <bits/stdc++.h>

using namespace std;

string ans;
int a, b, m;
int searched[1001][1001] = { 0 };
void print(string a){
 for(int i = 0; i < a.size(); i++){
   switch(a[i]){
     case '1':
     //chug a
     cout << "chug A" << endl;
     break;
     case '2':
     //chug b
      cout << "chug B" << endl;
     break;
     case '3':
     //fill a
      cout << "fill A" << endl;
     break;
     case '4':
     //fill b
      cout << "fill B" << endl;
     break;
     case '5':
     //pour a b
      cout << "pour A B" << endl;
     break;
     case '6':
     //pour b a
      cout << "pour B A" << endl;
     break;
   }
 }
}

void bfs(){
  list <pair <int, int>> qu;
  list <string> ways;
  pair <int, int> t;
  t.first = t.second = 0;
  qu.push_back(t);
  ways.push_back("");
  while(!qu.empty()){
    t = qu.front();
    string s = ways.front();
    qu.pop_front();
    ways.pop_front();
    if(searched[t.first][t.second] == 1)continue;
    searched[t.first][t.second] = 1;
     //   cout << t.first << " " << t.second << endl;
    //print(s);
   // cout << endl;
    if(t.first == m || t.second == m){
      ans = s;
      return;
    }
    //add neighbour
    if(t.first != 0){
      //chug a, 1
      pair <int, int> d;
      d = t;
      d.first = 0;
      qu.push_back(d);
      string x = s;
      x += '1';
      ways.push_back(x);
    }
    if(t.second != 0){
      //chug b, 2
      pair <int, int> d;
      d = t;
      d.second = 0;
      qu.push_back(d);
      string x = s;
      x += '2';
      ways.push_back(x);
    }
    if(t.first != a){
      //fill a, 3
      pair <int, int> d;
      d = t;
      d.first = a;
      qu.push_back(d);
      string x = s;
      x += '3';
      ways.push_back(x);
    }
    if(t.second != b){
      //fill b, 4
      pair <int, int> d;
      d = t;
      d.second = b;
      qu.push_back(d);
      string x = s;
      x += '4';
      ways.push_back(x);
    }
    if(t.first != 0 && t.second != b){
      //pour a, b, 5
      pair <int, int> d;
      d = t;
      if(d.first + d.second <= b){
        d.second += d.first;
        d.first = 0;
      }else{
        d.first = d.first + d.second - b;
        d.second = b;
      }
      qu.push_back(d);
      //
      string x = s;
      x += '5';
      ways.push_back(x);
    }
    if(t.first != a && t.second != 0){
      //pour b, a 6
      pair <int, int> d;
      d = t;
      if(d.first + d.second <= a){
        d.first += d.second;
        d.second = 0;
      }else{
        d.second = d.first + d.second - a;
        d.first = a;
      }
      qu.push_back(d);
      //
      string x = s;
      x += '6';
      ways.push_back(x);
    }
  }
  return;
}

int main() {
  cin >> a >> b >> m;
  bfs();
  if(ans.size() == 0)cout << "Not possible";
  else print(ans);
}