#include <bits/stdc++.h>

using namespace std;

int coins[2002] = {0}, dp[2][10002] = {0};
vector <pair <int, int>> queries;//first is the number of coins, second is target sum
vector <int> positions, newPositions;
int n, m;

void quickSort(int left, int right) {
	int i = left, j = right;
	pair <int, int> tmp;
	pair <int, int> pivot = queries[(left + right) / 2];
	/* partition */
	while (i <= j) {
		while (queries[i] < pivot)
			i++;
		while (queries[j] > pivot)
			j--;
		if (i <= j) {
			tmp = queries[i];
			queries[i] = queries[j];
			queries[j] = tmp;
      int t = positions[i];
      positions[i] = positions[j];
      positions[j] = t;
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

int main() {
  int maxTarget = 0;
  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    cin >> coins[i];
  }
  for(int i = 0; i < m; i++){
    int target, numCoins;
    cin >> target >> numCoins;
    queries.push_back(make_pair(numCoins, target));
    if(target > maxTarget)maxTarget = target;
    positions.push_back(i);
  }
  quickSort(0, m - 1);
  //create a queries
  list <pair <int, int>> qu;
  for(int i = 0; i < m; i++){
    qu.push_back(queries[i]);
    //cout << queries[i].first << ' ' << queries[i].second << endl;
  }
  //start dp
  for(int i = 0; i <= n; i++){
    for(int j = 0; j <= maxTarget; j++){
      //is -1 if you can't make it
      if(j == 0){
        dp[i%2][j] = 0;
      }else if(i == 0){
        dp[i % 2][j] = -1;
      }else {
        //find dp i%2, j
        int curSize = coins[i];
        if(j == curSize)dp[i%2][j] = 1;
        else if(j > curSize){
          //can take the current coin, max is between dp[i%2][j - curSize] and dp[(i - 1)%2][j]
          //take dp[i%2][j - curSize] or dp[(i - 1)%2][j]
          if(dp[i%2][j - curSize] == -1 && dp[(i - 1)%2][j] == -1){
            dp[i%2][j] = -1;
          }else if(dp[i%2][j - curSize] == -1){
            dp[i%2][j] = dp[(i - 1)%2][j];
          }else if(dp[(i - 1)%2][j] == -1){
            dp[i%2][j] = dp[i%2][j - curSize] + 1;
          }else{
            dp[i%2][j] = min(dp[i%2][j - curSize] + 1, dp[(i - 1)%2][j]);
          }
        }else{
          //can only take last one
          dp[i%2][j] = dp[(i - 1)%2][j];
          if(dp[i%2][j] <= 0)dp[i%2][j] = -1;
        }
        //done, check if in qu
        while(qu.front().first == i && qu.front().second == j){
          qu.pop_front();
          newPositions.push_back(dp[i%2][j]);
        }
        //cout << dp[i%2][j] << ' ';
      }
    }
    //cout << endl;
  }
  //make an outo put feed, newPositions is the answers, and positions i is where the ith element in newPositions should be
  vector <int> output;
  for(int i = 0; i < m; i++)output.push_back(0);
  for(int i = 0; i < m; i++){
    output[positions[i]] = newPositions[i];
  }
  for(int i = 0; i < m; i++)cout << output[i] << endl;
}