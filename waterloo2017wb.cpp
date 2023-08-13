#include <iostream>
#include <string>

using namespace std;

int n, k;
string a;

int main() {
	cin >> n >> k >> a;
	if (n < k)cout << "WRONGANSWER" << endl;
	else if (n == k)cout << a;
	else {
		int freq[26] = { 0 }, min = n + 1; char c;
		for (int i = 0; i < a.size(); i++) {
			freq[a[i] - 'a']++;
		}
		for (int i = 0; i < 26; i++) {
			if (freq[i] < min) {
				min = freq[i]; c = (char)('a' + i);
			}
		}
		if (min > k) {
			cout << "WRONGANSWER" << endl; return 0;
		}
		int cnt = min;
		for (int i = 0; i < n; i++) {
			if (cnt != k) {
				cout << a[i];
				if (a[i] != c)cnt++;
				
			}
			else cout << c;
		}
		cout << endl;
		cin.get();
		cin.get();
		cin.get();
		cin.get();
	}
}