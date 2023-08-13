#include <bits/stdc++.h>

using namespace std;

int n;
string a[10002];

bool cmp(string a, string b){
  string ab = a + b, ba = b + a;
  return ab > ba;
}

int main(){
  cin >> n;
  for(int i = 0; i < n; i++)cin >> a[i];
  sort(a, a + n, cmp);
  for(int i = 0; i < n; i++)cout << a[i];
  cout << endl;
}