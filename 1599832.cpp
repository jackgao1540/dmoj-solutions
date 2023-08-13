#include <bits/stdc++.h>

using namespace std;

int n;
long maxLen, maxNum, pieces[2001], boards[4001];

int main() {
    cin >> n;
    int a;
    for(int i = 0; i < n; i++) {
        cin >> a;
        pieces[a]++;
    }
    for(int i = 1; i <= 2000; i++) {
        if(pieces[i] != 0) {
            for(int j = i; j < 2001; j++) {
                if(i == j) boards[i + j] += pieces[i] / 2;
                else if(pieces[j] != 0) {
                    boards[i + j] += min(pieces[i], pieces[j]);
                }
            }
        }
    }
    for(int i=1;i<=4000;i++) {
        if(boards[i] > maxLen) {
            maxLen = boards[i];
            maxNum = 1;
        } else if(boards[i] == maxLen) {
            maxNum++;
        }
    }
    cout << maxLen << ' ' << maxNum << endl;
}