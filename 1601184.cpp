#include <bits/stdc++.h>

using namespace std;
int n, cnt; vector <int> a[3];
void print(int i){
  cnt++;
  printf("%d%c", a[i].back(), cnt == n ? '\n' : ' ');
  a[i].pop_back();
}

int main() {
  cnt = 0;
  cin >> n;
  for(int i = 0, x; i < n; i++){
    cin >> x;
    a[x%3].push_back(x);
  }
  if(a[0].size() > 1 + a[1].size() + a[2].size() || (a[0].empty() && !a[1].empty() && !a[2].empty())){
    cout << "impossible" << endl;
    return 0;
  }
  while(!a[1].empty()){
    if(a[0].size() > a[1].size()){
      print(0);
      print(1);
    }else  print(1);  
  }
  while(!a[2].empty()){
    if(!a[0].empty()){print(0); print(2);}
    else print(2);
  }
  if(!a[0].empty())print(0);
}