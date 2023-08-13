#include <iostream>

using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}

int min(int a, int b) {
	return a < b ? a : b;
}

/*
2 250
100 30 150 30 200 30
50 5 200 10 400 15

35

2 3
1 10 2 20 3 30
1 20 4 80 6 120

40

*/
int main() {
	int n, t;
	cin >> n >> t;
	int items[3][2002];
	int costs[3][2002];
	//poor, average and advanced
	for (int i = 0; i < n; i++) {
		cin >> costs[0][i] >> items[0][i];
		cin >> costs[1][i] >> items[1][i];
		cin >> costs[2][i] >> items[2][i];
	}
	int dp[2][10005] = { 0 };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= t; j++) {
			if (j == 0) {
				dp[i % 2][j] = 0;
			}
			else if (i == 0) {
				//can't check the previous row
				int v1, v2, v3;//item values
				int c1, c2, c3;//costs  
				v1 = items[0][i];
				v2 = items[1][i];
				v3 = items[2][i];
				c1 = costs[0][i];
				c2 = costs[1][i];
				c3 = costs[2][i];
				//check simultaneosly
				//check item 1
				if (j >= c1) {
					//can take the current item
					dp[i % 2][j] = max(dp[i % 2][j], v1);
				}
				//check item 2
				if (j >= c2) {
					dp[i % 2][j] = max(dp[i % 2][j], v2);
				}
				//check item 3
				if (j >= c3) {
					dp[i % 2][j] = max(dp[i % 2][j], v3);
				}
			}
			else {
				int v1, v2, v3;//item values
				int c1, c2, c3;//costs  
				v1 = items[0][i];
				v2 = items[1][i];
				v3 = items[2][i];
				c1 = costs[0][i];
				c2 = costs[1][i];
				c3 = costs[2][i];
				//check simultaneosly
				//check item 1
				if (j >= c1) {
					//can take the current item
					//take max of the (current value + last row) vs (last row current col)
					dp[i % 2][j] = max(dp[i % 2][j], max(v1 + dp[(i - 1)%2][j - c1], dp[(i - 1)%2][j]));
				}
				else {
					//take the max of the current value of dp[i][j] and dp[i - 1][j]
					dp[i % 2][j] = max(dp[i % 2][j], dp[(i - 1) % 2][j]);
				}
				//check item 2
				if (j >= c2) {
					dp[i % 2][j] = max(dp[i % 2][j], max(v2 + dp[(i - 1) % 2][j - c2], dp[(i - 1) % 2][j]));
				}
				else {
					//take the max of the current value of dp[i][j] and dp[i - 1][j]
					dp[i % 2][j] = max(dp[i % 2][j], dp[(i - 1) % 2][j]);
				}
				//check item 3
				if (j >= c3) {
					dp[i % 2][j] = max(dp[i % 2][j], max(v3 + dp[(i - 1) % 2][j - c3], dp[(i - 1) % 2][j]));
				}
				else {
					//take the max of the current value of dp[i][j] and dp[i - 1][j]
					dp[i % 2][j] = max(dp[i % 2][j], dp[(i - 1) % 2][j]);
				}
			}
			//cout << dp[i % 2][j] << ' ';
		}
		//cout << endl;
	}
	cout << dp[(n - 1) % 2][t];
	cin.get();
	cin.get();
	cin.get();
	cin.get();
	cin.get();
	cin.get();
	cin.get();
	return 0;
}