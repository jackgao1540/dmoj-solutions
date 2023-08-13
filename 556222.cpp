#include <iostream>

using namespace std;

int main() {
	int n;
	cin>>n;
	int r = 0;
	char answers[n];
	char stud[n];
	for (int i = 0; i < 2*n; i++) {
		if (i < n) {
			cin>>stud[i];
		}
		else {
			cin>>answers[i - n];
		}
	}
	for (int i = 0; i < n; i++) {
		if (stud[i] == answers[i]) {
			r++;
		}
	}
	cout << r;
	//this still works?
	cin.get();
	cin.get();
	return 0;
}