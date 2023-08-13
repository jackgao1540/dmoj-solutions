#include <iostream>

using namespace std;

int dp[300][300] = { 0 };

int numWays(int pies, int ppl) {
	if (pies < 0 || ppl < 1)return 0;
	if (pies == 0 || ppl == 1)return 1;
	else {
		if (dp[pies][ppl] > 0)return dp[pies][ppl];
		//cout << pies << ' ' << ppl << endl;
		dp[pies][ppl] = numWays(pies, ppl - 1) + numWays(pies - ppl, ppl);
		return dp[pies][ppl];
	}
}

int main() {
	int numPeople, numPies;
	cin >> numPies >> numPeople;
	numPies -= numPeople;
	cout << numWays(numPies, numPeople);
	cin.get(); cin.get(); cin.get(); cin.get(); cin.get(); cin.get(); cin.get();
}