#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; vector <int> arr;
    scanf("%d", &n);
    for(int i = 0, x; i < n; i++){
        scanf("%d", &x);
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());
    int ind = (int)((arr.size() - 1)/2) + 1;
    int a = ind - 1, b = ind;
    for(int i = 0; i < n; i++){
        if(ind - 1 - a == b - ind){
            //increment a
            cout << arr[a] << ' ';
            a -= 1;
        }else{
            //increment b
            cout << arr[b] << ' ';
            b += 1;
        }
    }
    return 0;
}