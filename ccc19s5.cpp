#include <bits/stdc++.h>

using namespace std;

int n, K, cur, nxt, arr[3001][3001] = {0};

int main() {
  scanf("%d %d", &n, &K);
  for(int i = 0; i < n; i++){
    for(int j = 0; j <= i; j++){
      scanf("%d", &arr[i][j]);
    }
  }
  for(cur = 1, nxt = 2; nxt <= K; cur = nxt, nxt = 1.5*cur){
    //generate the array for the current k
    int d = nxt - cur; 
    for(int i = 0; i < n - nxt + 1; i++){
      for(int j = 0; j <= i; j++){
        arr[i][j] = max(arr[i][j], max(arr[i + d][j], arr[i + d][j + d])); 
      }
    } 
  }
  int d = K - cur;
  long long sum = 0;
  for(int i = 0; i < n - K + 1; i++){
    for(int j = 0; j <= i; j++){
      sum += max(arr[i][j], max(arr[i + d][j], arr[i + d][j + d]));
      //cout << arr[K%2][i][j] << ' ';
    }
    //cout << endl;
  }
  printf("%lld\n", sum);
}