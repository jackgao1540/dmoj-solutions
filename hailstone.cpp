#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int count;
    cin>>n;
    while(n != 1){
        if(n%2){
            //odd
            n *= 3;
            n++;
            count++;
        }else{
            //even
            n /= 2;
            count++;
        }
    }
    cout<<count;
    return 0;
}