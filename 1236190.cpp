#include <iostream>

using namespace std;

int values[2000][2000] = { 0 };
int n;

int min(int a, int b) {
	return a < b ? a : b;
}

int dp() {
	int total = 0;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = n - 1; j >= 0; j--) {
			if(values[i][j] >= 1 && i + 1 < n && j + 1 < n && j - 1 >= 0)
				values[i][j] += min(values[i + 1][j], min(values[i + 1][j - 1], values[i + 1][j + 1]));
			total += values[i][j];
		}
	}
	return total;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char c;
			cin >> c;
			values[i][j] += (c == '#');
		}
	}
	cout << dp();
}