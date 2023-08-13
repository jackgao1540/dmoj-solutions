#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int N, W;
	cin >> N >> W;
	vector <pair <unsigned long long, int>> items;
	vector <unsigned long long> tmp;
	for (int i = 0; i <= W; i++) {
		tmp.push_back(0);
	}
	vector <vector <unsigned long long>> dp;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		items.push_back(make_pair(b, a));
		//cout << items[i].first << ' ' << items[i].second << endl;
	}
  dp.push_back(tmp);
  dp.push_back(tmp);
	//actual dp
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= W; j++) {
			if (j == 0)dp[i%2][j] = 0;
			else if (i == 0) {
				//can't take from previous row
				if (items[i].second > j)dp[i%2][j] = 0;
				else dp[i%2][j] = items[i].first;
			}
			else {
				if (items[i].second > j)dp[i%2][j] = dp[(i - 1)%2][j];
				else dp[i%2][j] = max(items[i].first + dp[(i - 1)%2][j - items[i].second], dp[(i - 1)%2][j]);
			}
			//cout << dp[i][j] << ' ';
		}
		//cout << endl;
	}
	cout << dp[(N - 1)%2][W];
	return 0;
}