#include <iostream>
#include <vector>

using namespace std;

vector <int> arr{0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};
long long dp[40];

void quickSort(int left, int right) {
	int i = left, j = right;
	int tmp;
	int pivot = arr[(left + right) / 2];
	/* partition */
	while (i <= j) {
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	};
	/* recursion */
	if (left < j)
		quickSort(left, j);
	if (i < right)
		quickSort(i, right);
}

int main(){
  int a, b, n;
  cin >> a >> b >> n;
  for(int i = 0; i < n; i++){
    int d;
    cin >> d;
    arr.push_back(d);
  }
  quickSort(0, arr.size() - 1);
  dp[0] = 1;
  for(int i = 1; i < arr.size(); i++){
    for(int j = i - 1; j >= 0; j--){
      int diff = arr[i] - arr[j];
      if(diff < 0)diff = -diff;
      if(diff > b)break;
      if(a <= diff){
        dp[i] += dp[j]; 
      }
    }
    //cout << dp[i] << ' ';
  }
  //cout << endl;
  cout << dp[arr.size() - 1] << endl;
}