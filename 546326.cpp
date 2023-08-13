#include <iostream>
#include <string>

using namespace std;

int main() {
	string r;
	int lower = 0;
	int upper = 0;
		getline(cin, r);
		for (char x : r) {
			if (isupper(x)) upper++;
			if (islower(x)) lower++;
		}
		if (upper > lower) {
			for (char x : r) {
				char d = toupper(x);
				if (islower(x))cout << d; else cout << x;
			}
		}
		else if (lower > upper) {
			for (char x : r) {
				char d = tolower(x); if (isupper(x))cout << d; else cout << x;
			}
		}
		else if(upper == lower) {
			cout << r;
		}
		cout << endl;
	return 0;
}