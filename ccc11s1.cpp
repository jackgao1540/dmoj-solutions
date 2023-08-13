#include <iostream>
#include <string>

using namespace std;

int main() {
	int tcount, scount, n;
	cin >> n;
	tcount = 0;
	scount = 0;
	string s;
	for (int i = 0; i < n+1; i++) {
		s = "";
		getline(cin, s);
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == 115 || s[j] == 83) {
				//s
				scount++;
				continue;
			}
			else if (s[j] == 84 || s[j] == 116) {
				//t
				tcount++;
				continue;
			}
		}
	}
	if (scount >= tcount) {
		cout << "French";
	} else{
		cout << "English";
	}
	cin.get();
	cin.get();
	return 0;
}