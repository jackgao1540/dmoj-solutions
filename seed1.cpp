#include <bits/stdc++.h>

using namespace std;

int main() {
    bool hasB = false;
    bool hasF = false;
    bool hasT = false;
    bool hasL = false;
    bool hasC = false;
    string s;
    cin>>s;
    for(unsigned int i = 0; i < s.size(); i++){
        switch(s[i]){
            case 66://B
            hasB = true;
            break;
            case 70://F
            hasF = true;
              break;
            case 84://T
            hasT = true;
              break;
            case 76://L
            hasL = true;
              break;
            case 67://C
            hasC  = true;
        }
    }
   
    if(!hasB) cout<<"B "<<endl;
    if(!hasF) cout<<"F "<<endl;
    if(!hasT) cout<<"T "<<endl;
    if(!hasL) cout<<"L "<<endl;
    if(!hasC) cout<<"C "<<endl;
    if(hasB && hasF && hasT && hasL && hasC) cout<< "NO MISSING PARTS";
    return 0;
}