#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
    int n;
     long long int a; 
     long long int b;
     long long int c;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>a>>b>>c;
        if(a*b == c){
            cout<<"POSSIBLE DOUBLE SIGMA"<<endl;
        }else{
            cout<<"16 BIT S/W ONLY"<<endl;
        }
        
    }
    return 0;
}