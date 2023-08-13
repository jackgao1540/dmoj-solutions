#include <bits/stdc++.h>

using namespace std;

void output(string s){
  int arr[5][s.size()];
  memset(arr, -1, sizeof(arr));
  for(int i = 0; i < s.size(); i++){
    arr[0][i] = s[i] == '.' ? -1 : s[i] - '0';
  }
  int n = s.size();
  for(int i = 0; i < n; i++){
    if(arr[0][i] != -1){
      for(int j = 1, k = i + arr[0][i]; j < 5 && k < n; j++, k+= arr[0][i]){
        if(arr[j][k] == -1)arr[j][k] = arr[0][i];
        else arr[j][k] += arr[0][i];
      }
    }
  }
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < n; j++)cout << (char)(arr[i][j] == -1 ? '.' : arr[i][j] + '0');
    cout << endl;
  }
}

int main() {
  for(int i = 0; i < 5; i++){
    string s;
    cin >> s;
    output(s);
  }
}