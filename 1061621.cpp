#include <iostream>
#include <string>

using namespace std;

bool isWord(string s) {
	//cout << s << endl;
	int sPos = s.find('S');
	//cout << sPos << endl;
	int bCount = 0, sCount = 1, oldPos;
	for (int i = 0; i < sPos; i++)if (s[i] == 'B')bCount++;
	while (bCount != sCount) {
		oldPos = sPos;
		sPos = s.find('S', sPos + 1);
		//cout << sPos << endl;
		if (sPos == string::npos)break;
		for (int i = oldPos + 1; i < sPos; i++) {
			if (s[i] == 'B')bCount++;
		}
		sCount++;
	}
	if (s.front() == 'A') {
		if (s.size() > 1 && s[1] == 'N')return isWord(s.substr(2, s.size() - 2));
		else if (s.size() > 1)return false;
		else return true;
	}
	else if (s.front() == 'B' && sPos != string::npos) {
		if (sPos == s.size() - 1) {
			return isWord(s.substr(1, s.size() - 2));
		}
		else if(s[sPos + 1] == 'N'){
			return (isWord(s.substr(1, sPos - 1)) && isWord(s.substr(sPos + 2)));
		}
		else return false;
	}
	else return false;
}

int main() {
	string s;
	cin >> s;
	while (s.front() != 'X') {
		cout << (isWord(s) ? "YES" : "NO") << endl;
		cin >> s;
	}
	return 0;
}