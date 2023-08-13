#include <iostream>
#include <cmath>

using namespace std;
//Sibice
int main() {
	int w, l, h, n, r;
	cin >> n >> w >> l;
	h = sqrt((w*w) + (l * l));
	for (int i = 0; i < n; i++) {
		cin >> r;
		if (r <= h) {
			cout << "DA" << endl;
		}
		else {
			cout << "NE" << endl;
		}
	}
	return 0;
}