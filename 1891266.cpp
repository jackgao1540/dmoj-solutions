#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector <bool> planets;
    for(int i = 0; i < n; i++){
        bool k;
        cin >> k;
        planets.push_back(k);
    }
    int i = 0, ans = 0;
    while(i < n){
        if(planets[i] == false){i++; continue;}
        i++;
        ans++;
        while(i < n && planets[i] == true)i++;
    }
    cout << ans << endl;
    return 0;
}