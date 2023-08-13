#include <iostream>

using namespace std;

int main() {
  int n;
  int numbers[200002] = {0};
  unsigned long long psa[200001] = {0};
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> numbers[i];
    psa[i] = psa[i - 1] + numbers[i];
    //cout << psa[i] << ' ';
  }
  //cout << endl;
  unsigned long long int totSum = psa[n];
  cout << totSum << endl;
  for(int k = 2; k <= n; k++){
    totSum += psa[n - k + 1];
    totSum -= psa[k - 1];
    cout << totSum << endl;
  }
}