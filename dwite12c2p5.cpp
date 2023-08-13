#include <bits/stdc++.h>

using namespace std;

int main() {
  for(int g = 0; g < 5; g++){
    int n , k;
    cin >> n >> k;
    vector <int> numbers;
    for(int i = 0; i < n; i++){
      int d;
      cin >> d;
      numbers.push_back(d);
    }
    int pos = 0;
    int numGuards = 0;
    while(pos <= n - 1){
      int mx = 0, maxPos;
      if(pos == n -1){
        numGuards++;
        break;
      }
      mx = numbers[pos], maxPos = pos;
      //find maximum position that can cover pos
      for(int i = pos + 1; i <= min(pos + k, n - 1); i++){
        if(numbers[i] >= mx){
          mx = numbers[i];
          maxPos = i;
        }
      }
      numGuards++;
      //cout << maxPos << endl;
      if(maxPos == n - 1)break;
      //find the next pos
      int nextPos = -1;
      for(int i = maxPos; i <= min(maxPos + k, n - 1); i++){
        if(numbers[i] > mx){
          nextPos = i; 
          break;
        }
      }
      if(nextPos == -1)pos = min(maxPos + k + 1, n);
      else pos = nextPos;
    }
    cout << numGuards << endl;
  }
}