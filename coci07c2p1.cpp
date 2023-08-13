#include <bits/stdc++.h>

using namespace std;

int main() {
    for(int i = 0; i < 6; i++){
        int a;
        cin>>a;
        switch(i){
            case 0:
            cout<<(1 - a)<<" ";
            break;
            case 1:
            cout<<(1 - a)<<" ";
            break;
            case 2:
            cout<<(2 - a)<<" ";
            break;
            case 3:
            cout<<(2 - a)<<" ";
            break;
            case 4:
            cout<<(2 - a)<<" ";
            break;
            case 5:
            cout<<(8 - a)<<" ";
            break;
        }
    }
    return 0;
}