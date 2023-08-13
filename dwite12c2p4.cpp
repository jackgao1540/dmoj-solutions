#include <bits/stdc++.h>

using namespace std;

int main() {
  for(int k = 0; k < 5; k++){
    int n;
    vector <int> numLargerAfter;
    cin >> n;
    for(int i = 0; i < n; i++){
      int d;
      cin >> d;
      numLargerAfter.push_back(d);
    }
    if(numLargerAfter[n - 1] > 0)cout << "IMPOSSIBLE" << endl;
    else{
      set <int> numbers;
      vector <int> numSmallerThan;
      for(int i = 1; i <= n; i++){
        numbers.insert(i);
        numSmallerThan.push_back(n - i);
      }
      vector <int> arr;
      for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
          if(numbers.find(j + 1) != numbers.end()){
            if(numSmallerThan[j] == numLargerAfter[i]){
              numbers.erase(j + 1);
              arr.push_back(j + 1);
              //adjust numSmallerThan
              for(int l = 0; l < j; l++){
                numSmallerThan[l]--;
              }
            }
          }
        }
      }
      for(int i = 0; i < n; i++)cout << arr[i] << ' ';
      cout << endl;
    }
  }
}