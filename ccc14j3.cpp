#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;
    int a;
    int b;
    int ap, bp;
    ap = 100;
    bp = ap;
    for(int i  = 0; i < n; i++){
        cin>>a>>b;
        if(a>b){
            bp -= a;
        }else if (b>a){
            ap -= b;
        }
    }
    cout<<ap<<endl<<bp;
    return 0;
}