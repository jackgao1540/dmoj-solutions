#include <iostream>

using namespace std;

int main() {
	int n;
	//all 1 indexed
	int riceballs[401] = { 0 };
	long psa[401] = { 0 };
	long dp[401][401] = { 0 };
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> riceballs[i];
		psa[i] = riceballs[i] + psa[i - 1];
	}
	//dp
	long maxx = 0;
	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= n; y++) {
			int i, j;
			i = y;
			j = x + y - 1;
			if (j > n)break;
			if (j > i) {
				int p = i, q = j;
				while (p < q) {
					//i ... p, p + 1 ... q - 1, q ... j
					int sum1 = psa[p] - psa[i - 1];
					int sum2 = psa[j] - psa[q - 1];
					int ball1 = dp[i][p];
					int ball2 = dp[q][j];
					int mid = dp[p + 1][q- 1];
					if (p + 1 == q) {
						if (ball1 != 0 && ball1 == ball2) {
							dp[i][j] = ball1 + ball2;
							if (dp[i][j] > maxx)maxx = dp[i][j];
						}
						break;
					}
					else if (ball1 != 0 && ball1 == ball2 && mid != 0) {
						dp[i][j] = ball1 + ball2 + mid;
						if (dp[i][j] > maxx)maxx = dp[i][j];
						break;
					}
					else if (sum1 > sum2) {
						q--;
						continue;
					}
					else {
						p++;
						continue;
					}
				}
			}
			else if (j == i) {
				dp[i][j] = riceballs[i];
				if (dp[i][j] > maxx)maxx = dp[i][j];
			}
			else dp[i][j] = 0;
			//cout << dp[i][j] << " (" << i << ", " << j << "), ";
		}
		//cout << endl;
	}
	cout << maxx;

	cin.get();
	cin.get();
	cin.get();
	cin.get();
}