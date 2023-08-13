#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;

vector <string> graph;
int rows, columns, a, b, x, y, numTel;
int off = -1, tel = -1;
vector <vector <int>> searched;

void bfs(){
  list <pair <int, int>> qu;
  pair <int, int> start;
  start.first = a;
  start.second = b;
  qu.push_back(start);
  pair <int, int> cur, dest;
  dest.first = x;
  dest.second = y;
  int dist;
  list <int> distances;
  distances.push_back(0);
  while(!qu.empty()){
    cur = qu.front();
    qu.pop_front();
    dist = distances.front();
    distances.pop_front();
    if(searched[cur.first][cur.second])continue;
    searched[cur.first][cur.second] = 1;
    if(graph[cur.first][cur.second] == 'X')continue;
    if(off > 0 && tel > 0)return;
    if(graph[cur.first][cur.second] == 'T'){
      if(tel == -1)tel = dist;
    }
    if(cur == dest){
      if(off == - 1)off = dist;
    }
    pair <int, int> temp;
    //add neighbours
    if(cur.first < rows - 1){
      temp = cur;
      temp.first += 1;
      qu.push_back(temp);
      distances.push_back(dist + 1);
    }
    if(cur.first > 0){
      temp = cur;
      temp.first -= 1;
      qu.push_back(temp);
      distances.push_back(dist + 1);
    }
    if(cur.second < columns - 1){
      temp = cur;
      temp.second += 1;
      qu.push_back(temp);
      distances.push_back(dist + 1);
    }
    if(cur.second > 0){
      temp = cur;
      temp.second -= 1;
      qu.push_back(temp);
      distances.push_back(dist + 1);
    }
  }
  return;
}

int main() {
  cin >> rows >> columns >> a >> b >> x >> y;
  string temp;
  vector <int> t;
  for(int i = 0; i < columns; i++)t.push_back(0);
  for(int i = 0; i < rows; i++){
    cin >> temp;
    graph.push_back(temp);
    searched.push_back(t);
  }  
  cin >> numTel;
  int c, d;
  for(int i = 0; i < numTel; i++){
    cin >> c >> d;
    graph[c][d] = 'T';
  }
  bfs();
  cout /*<< off << " " << tel << " " */<< off - tel;
  return 0;
}