#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;
/*
Sample Cases:
2
 27 5
 OOCOOOOOOOOOOOOOOOOOOOOOOOO
 XXXXXXXXXXXXXXXXXXXXXXXXXXO
 OOOOOOOOOOOOOOOOOOOOOOOOOOO
 OXXXXXXXXXXXXXXXXXXXXXXXXXX
 OOOOOOOOOOOOOOOOOOOOOOOOOWO
 5 5
 OOOOO
 OOOOO
 OXXOO
 OWXCO
 OOXOO
 Expected out:
 #notworth
 8
*/
int rows, columns, x, y;
vector <string> graph;
vector <vector <int>> searched;

int bfs(){
  list <pair <int, int>> qu;
  list <int> distances;
  distances.push_back(0);
  pair <int, int> temp;
  temp.first = x;
  temp.second = y;
  qu.push_back(temp);
  while(!qu.empty()){
    pair <int, int> cur = qu.front();
    qu.pop_front();
    int curDist = distances.front();
    distances.pop_front();
    if(searched[cur.first][cur.second])continue;
    if(graph[cur.first][cur.second] == 'X')continue;
    if(graph[cur.first][cur.second] == 'W'){
      return curDist;
    }
    searched[cur.first][cur.second] = 1;
    pair <int, int> t;
    if(cur.first > 0){
      t = cur;
      t.first--;
      qu.push_back(t);
      distances.push_back(curDist + 1);
    }
    if(cur.first < rows - 1){
      t = cur;
      t.first++;
      qu.push_back(t);
      distances.push_back(curDist + 1);
    }
    if(cur.second > 0){
      t = cur;
      t.second--;
      qu.push_back(t);
      distances.push_back(curDist + 1);
    }
    if(cur.second < columns - 1){
      t = cur;
      t.second++;
      qu.push_back(t);
      distances.push_back(curDist + 1);
    }
  }
  return -1;
}

int main(){
  int cases;
  cin >> cases;
  for(int fadsfsad = 0; fadsfsad < cases; fadsfsad++){
    cin >> columns >> rows;
    for(int i = 0; i < rows; i++){
      string s = "";
      vector <int> temp;
      searched.push_back(temp);
      for(int j = 0; j < columns; j++){
        char c; 
        cin >> c;
        if(c == 'C'){
          x = i;
          y = j;
        }
        s.push_back(c);
        searched[i].push_back(0);
      }
      graph.push_back(s);
      //cout << s << endl;
    }
    int dist = bfs();
    if((dist >= 60)||(dist == -1))cout << "#notworth" << endl;
    else cout << dist << endl;
    graph.clear();
    searched.clear();
  }
  return 0;
}