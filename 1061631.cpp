#include <iostream>
#include <vector>
#include <list>

using namespace std;

struct node{
  vector <int> shawties;
  vector <int> tallerppl;
};

int n, m, p, q;
node people[1000001];
bool searched[1000001] = {0};

void setSearched(){
  for(int i = 0; i <= n; i++)searched[i] = 0;
}

int bfs(){
  //find out if taller
  list <int> qu;
  qu.push_back(p);
  while(!qu.empty()){
    int cur = qu.front();
    qu.pop_front();
    if(searched[cur])continue;
    searched[cur] = 1;
    if(cur == q)return 1;
    for(int i = 0; i < people[cur].shawties.size(); i++){
      qu.push_back(people[cur].shawties[i]);
    }
  }
  setSearched();
  qu.clear();
  qu.push_back(p);
  while(!qu.empty()){
    int cur = qu.front();
    qu.pop_front();
    if(cur == q)return 0;
    if(searched[cur])continue;
    searched[cur] = 1;
    for(int i = 0; i < people[cur].tallerppl.size(); i++){
      qu.push_back(people[cur].tallerppl[i]);
    }
  }
  return -1;
}

int main() {
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    people[a].shawties.push_back(b);
    people[b].tallerppl.push_back(a);
  }
  cin >> p >> q;
  int is = bfs();
  if(is == 1)cout << "yes";
  else if(is == 0) cout << "no";
  else cout << "unknown";
}