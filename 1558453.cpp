#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector <int> arr, tmp, pos;
  for(int i = 0; i < n; i++)pos.push_back(0);
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    arr.push_back(x - 1);
    pos[x - 1] = i;
    tmp.push_back(i);
  }
  int cnt = 0;
  for(int i = n - 1; i >= 0; i--){
    if(cnt >= k)break;
    int arrPos = n - 1 - i;
    if(tmp[i] != arr[arrPos]){
      //swap
      cnt++;
      arr[pos[i]] = arr[arrPos];
      pos[arr[arrPos]] = pos[i];
      pos[tmp[i]] = arrPos;
      arr[arrPos] = tmp[i];
    }else continue;
  }
  for(int i = 0; i < n; i++)cout << arr[i] + 1 << ' ';
  cout << endl;
}