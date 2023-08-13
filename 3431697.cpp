#include <bits/stdc++.h>
using namespace std;
const int MM = 5000*5000+5;

int main() {
  int arr[MM];
  memset(arr, 0, sizeof(arr));
  int N, M, Q;
  cin >> N >> M >> Q;
  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= M; j++){
      int mn = i * j;
      int mx = N*M - (N - i + 1)*(M - j + 1) + 1;
      arr[mn] += 1;
      arr[mx + 1] -= 1;
      //cout << '(' << mn << ", " << mx << "), ";
    }
    //cout << endl;
  }
  arr[0] = 0;
  arr[1] = 1;
  for(int i = 1; i <= N*M; i++){
    arr[i] += arr[i - 1];
    //cout << "answer for" << i << ": " << arr[i] << endl;
  }
  for(int i = 1; i <= Q; i++){
      int q;
      cin >> q;
      cout << arr[q] << endl;
  }
}