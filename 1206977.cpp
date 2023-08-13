#include <iostream>
#include <cmath>

using namespace std;

long max(long a, long b) {
	return a > b ? a : b;
}

long min(long a, long b) {
	return a < b ? a : b;
}

long GCD(long a, long b) {
	//a > b
	if (b == 0) return a;
	else return GCD(b, a % b);
}

long returnLargestPF(long d) {
	long greatestPrimeFactor = 1;
	long newD = d;
	while (newD % 2 == 0) {
		greatestPrimeFactor = 2;
		newD /= 2;
	}
	for (int i = 3; i <= sqrt(d) + 1; i += 2) {
		while (newD % i == 0) {
			greatestPrimeFactor = i;
			newD /= i;
		}
	}
	if (newD > 2 && newD > greatestPrimeFactor)return newD;
	return greatestPrimeFactor;
}

int main() {
	int n;
	cin >> n;
	long d;
	long gcd;
	cin >> d;
	gcd = d;
	for (int i = 1; i < n; i++) {
		cin >> d;
		gcd = GCD(max(gcd, d), min(gcd, d));
	}
	//cout << gcd << endl;
  long r = returnLargestPF(gcd);
  if(r == 1)cout << "DNE";
  else cout << r;
	return 0;
}