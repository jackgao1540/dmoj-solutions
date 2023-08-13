#include <iostream>
#include <vector>
#include <list>

using namespace std;

/*
Sample Cases:
3
2
2
-|
*+
3
5
+||*+
+++|+
**--+
2
3
+*+
+*+
Expected output:
3
|||||||||||||||||||||
1
2
6
- | * - - |
* - - | * +
Expected output:
9

*/

int bfs(int a, int b, vector<vector <int>> maze, vector <vector <int>> visited){
  pair <int, int> start;
  start.first = 0;
  start.second = 0;
  list <pair <pair <int, int>,  int>> qu;
  pair <pair <int, int>, int> temp;
  temp.first = start;
  temp.second = 1;
  qu.push_back(temp);
  pair <pair <int, int>, int> cur;
  bool found = 0;
  while(!qu.empty()){
    cur  = qu.front();
    qu.pop_front();
    if(maze[cur.first.first][cur.first.second] == '*')continue;
    if(visited[cur.first.first][cur.first.second] == 1)continue;
    if(cur.first.first == a - 1 && cur.first.second == b - 1){
      found  = 1;
      break;
    }
    visited[cur.first.first][cur.first.second] = 1;
    //cout << cur.first.first << " " << cur.first.second << endl;
    pair <pair <int, int>, int> d;
    pair <int, int> t;
    switch(maze[cur.first.first][cur.first.second]){
      case '|':

        //add the one to the bottom
        if(cur.first.first < a - 1){
          t.first = cur.first.first + 1;
          t.second = cur.first.second;
          d.first = t;
          d.second = cur.second + 1;
          qu.push_back(d);
        }
        if(cur.first.first > 0){
          t.first = cur.first.first - 1;
          t.second = cur.first.second;
          d.first = t;
          d.second = cur.second + 1;
          qu.push_back(d);
        }
      break;
      case '-':

        if(cur.first.second < b - 1){
          t.first = cur.first.first;
          t.second = cur.first.second + 1;
          d.first = t;
          d.second = cur.second + 1;
          qu.push_back(d);
        }
        //add the one to the right
        if(cur.first.second > 0){
          t.first = cur.first.first;
          t.second = cur.first.second - 1;
          d.first = t;
          d.second = cur.second + 1;
          qu.push_back(d);
        }
      break;
      case '+':

        //add the one to the bottom
        if(cur.first.first < a - 1){
          t.first = cur.first.first + 1;
          t.second = cur.first.second;
          d.first = t;
          d.second = cur.second + 1;
          qu.push_back(d);
        }
        if(cur.first.second < b - 1){
          t.first = cur.first.first;
          t.second = cur.first.second + 1;
          d.first = t;
          d.second = cur.second + 1;
          qu.push_back(d);
        }
        if(cur.first.second > 0){
          t.first = cur.first.first;
          t.second = cur.first.second - 1;
          d.first = t;
          d.second = cur.second + 1;
          qu.push_back(d);
        }
        if(cur.first.first > 0){
          t.first = cur.first.first - 1;
          t.second = cur.first.second;
          d.first = t;
          d.second = cur.second + 1;
          qu.push_back(d);
        }
      break;
    }
  }
  if(found){
    return cur.second;
  }else return -1;
}

int main() {
  int cases;
  cin >> cases;
  for(int l = 0; l < cases; l++){
    vector <vector <int>> maze;
    vector <vector <int>> visited;
    int a, b;
    cin >> a >> b;
    vector <int> temp;
    for(int i = 0; i < a; i++){
      for(int j = 0; j < b; j++){
        char c;
        cin >> c;
        maze.push_back(temp);
        visited.push_back(temp);
        visited[i].push_back(0);
        maze[i].push_back(c);
      }
    }
    cout << bfs(a, b, maze, visited) << endl;
  }
}