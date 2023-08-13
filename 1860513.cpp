#include <bits/stdc++.h>

using namespace std;

int main() {
    int nQ, ans = 0, ind = 0;
    int timesPlayed[3], period[3], value[3];
    period[0] = 35; period[1] = 100; period[2] = 10;
    value[0] = 30, value[1] = 60, value[2] = 9;
    cin >> nQ;
    for(int i = 0; i < 3; i++){
        cin >> timesPlayed[i];
    }
    while(nQ > 0){
        ind = ind % 3;
        nQ -= 1;
        ans += 1;
        timesPlayed[ind] += 1;
        if(timesPlayed[ind] % period[ind] == 0)nQ += value[ind];
        ind++;
    }
    cout << "Martha plays " <<  ans << " times before going broke." << endl;
    return 0;
}