#include <bits/stdc++.h>

using namespace std;

int n;
int numWays = 0;

void vout(vector <int> l){
  cout << n << "=";
  cout << l[0];
  for(int i = 1; i < l.size(); i++)cout << "+" << l[i];
  cout << endl;
}

void fun(int start, int sum, vector <int> l){
  if(sum == n){
    //print out and return
    vout(l);
    numWays++;
    return;
  }else if(sum > n)return;
  if(sum == 0){
  for(int i = start; i <= n/2; i++){
    vector <int> newL = l;
    newL.push_back(i);
    fun(i, sum + i, newL);
  }
  }else{
    for(int i = start; i <= n - sum; i++){
    vector <int> newL = l;
    newL.push_back(i);
    fun(i, sum + i, newL);
  }
  }
  return;
}

int main() { 
  cin >> n;
  vector <int> tmp;
  fun(1, 0, tmp);
  cout << "total=" << numWays;
}