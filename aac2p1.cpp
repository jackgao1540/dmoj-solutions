#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int alphabet[26] = {0};
    for(int i = 0; i < n; i++){
        char c;
        cin >> c;
        alphabet[(int)(c - 'a')]++;
    }
    int score = 0;
    for(int i = 0; i < 26; i++){
        score += alphabet[i]%2;
    }
    cout << max(1, score) << endl;
    return 0;
}