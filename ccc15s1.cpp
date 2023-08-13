#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector <int> l;
    for(int i = 0; i < n; i++){
        int r;
        cin>>r;
        if(r != 0){
            l.push_back(r);
        }else{
            l.pop_back();
        }
    }
    int sum = 0;
    for(int i = 0; i < l.size(); i++){
        sum += l[i];
    }
    cout<<sum;
    return 0;
}