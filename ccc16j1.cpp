#include <bits/stdc++.h>

using namespace std;

int main() {
    int num_W = 0;
    for(int  i =0; i < 6; i++){
        char c;
        cin>>c;
        if(c == 'W'){
            num_W++;
        }
    }
    if(num_W == 0){
        cout<<"-1";
    }else if(num_W == 1 || num_W == 2){
        cout<<"3";
    }else  if(num_W == 3 || num_W == 4){
        cout<<"2";
    }else {
        cout<<"1";
    }
    return 0;
}