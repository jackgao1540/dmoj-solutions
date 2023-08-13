#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    vector <int> recruits;
    int t;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> t;
        recruits.push_back(t);
    }
    int  ugCount = 0;
    for(int i = 0; i < n; i++){
        if(i == 0){
            if(recruits[i] <= 41 && recruits[i + 1] <= 41)ugCount++;
        }else if(i == n - 1){
             if(recruits[i] <= 41 && recruits[i +- 1] <= 41)ugCount++;
        }else{
             if(recruits[i] <= 41 && recruits[i + 1] <= 41 && recruits[i - 1] <= 41)ugCount++;
        }
    }
    cout << ugCount;
    return 0;
}