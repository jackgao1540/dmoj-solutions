#include <iostream>

using namespace std;

typedef unsigned long long ll;

ll dp[401][401] = { 0 };
ll psa[401] = { 0 };
int n;

ll min(ll a, ll b) {
	return a < b ? a : b;
}

ll fun(int l, int r) {
	if (dp[l][r] > 0)return dp[l][r];
	if (l == r)return 0;
	ll mi = 1e18;
	for (int k = l; k < r; k++) {
		mi = min(mi, fun(l, k) + fun(k + 1, r) + psa[r] - psa[l - 1]);
	}
	return dp[l][r] = mi;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> psa[i];
		psa[i] += psa[i - 1];
		//cout << psa[i] << ' ';
	}
	//cout << endl;
	cout << fun(1, n);
	cin.get();
	cin.get();
	cin.get();
	cin.get();
	cin.get();
	cin.get();
	cin.get();
}