#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}

int min(int a, int b) {
	return a < b ? a : b;
}

int main() {
	int num, maxppl;
	vector <string> names;
	vector <int> people;
	vector <long long> dp;
	vector <int> last;
	last.push_back(-1);
	dp.push_back(0);
	names.push_back("");
	people.push_back(0);

	cin >> maxppl >> num;
	for (int i = 0; i < num; i++) {
		string name;
		int d;
		cin >> name >> d;
		names.push_back(name);
		people.push_back(d);
		dp.push_back(0);
		last.push_back(-1);
	}
	dp[0] = 0;
	last[0] = -1;
	for (int i = 1; i <= num; i++) {
		//1 <= j <= min(maxppl, i)
		//dp[i] = max(dp[i], dp[i - j] + max(people[i - j + 1], people[i - j + 2] ... people[i - 1], people[i]))
		//first case: last[i] = last[i]
		//second case: last[i] = i - j
		int curMax = people[i];
		dp[i] = dp[i - 1] + people[i];
		last[i] = i - 1;

		//cout << i << endl;
		//j is the group size
		for (int j = 2; j <= min(maxppl, i); j++) {
			//take the curmax is the maximum of all members from i - j + 1 to i
			curMax = max(curMax, people[i - j + 1]);
			//dp[i] is the maximum of its current state and the state where it takes dp[i - j] + curMax
			if (dp[i] >= dp[i - j] + curMax) {
				dp[i] = dp[i - j] + curMax;
				last[i] = i - j;
			}
			//cout << " " << i - j + 1 << " - " << i << "  Max: " << curMax << endl;
		}
		//cout << "   " << dp[i] << ' ' << last[i] << endl;
	}
	//print out total time
	cout << "Total Time: " << dp[num] << endl;
	//get a vector to store the names
	vector <int> checkpoints;
	int c = num;
	while (c != 0) {
		checkpoints.push_back(c);
		c = last[c];
	}
	int j = 1;
	//first name of the list
	for (int i = checkpoints.size() - 1; i >= 0; i--) {
		for (j; j <= checkpoints[i]; j++) {
			cout << names[j] << ' ';
		}
		cout << endl;
	}
	cin.get();
	cin.get();
	cin.get();
	cin.get();
	cin.get();
	cin.get();
	cin.get();
	return 0;
}