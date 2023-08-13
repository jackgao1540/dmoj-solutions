#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, t, k, v;
  deque <int> rPos;
  bool restaurants[1000002] = {0};
  cin >> n >> t >> k >> v;
  for(int i = 0; i < v; i++){
    int d;
    cin >> d;
    restaurants[d] = true;
  }
  for(int i = 1; i <= t - 1; i++){
    if(!restaurants[i])rPos.push_back(i);
  }
  int rAdded = 0;
  for(int i = t; i <= n; i++){
    //update deque
    while(!rPos.empty() && rPos.front() <= i - t)rPos.pop_front();
    if(!restaurants[i])rPos.push_back(i);
    //number of restaurants is just t - rPos.size()
    int numR = t - rPos.size();
    //cout << numR << ' ';
    if(numR >= k)continue;
    else{
      //greedily add restaurants to the left
      while(numR < k){
        rAdded++;
        restaurants[rPos.back()] = true;
        rPos.pop_back();
        numR++;
      }
    }
  }
  //cout << endl;
  cout << rAdded << endl;
}