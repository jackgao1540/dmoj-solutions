#include <bits/stdc++.h>

using namespace std;

int main() {
    vector <int> arr;
    int n;
    cin >> n;
    for(int i = 0, x; i < n; i++){
        cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());
    for(int i = 0, x; i < n; i++){
        cout << arr[i] << endl;
    }
    return 0;
}