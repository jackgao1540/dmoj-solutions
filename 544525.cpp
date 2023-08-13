#include <bits/stdc++.h>

using namespace std;

int main() {
    int c, r;
    cin>>c>>r;
    int xmove, ymove, x, y;
    xmove = -1;
    ymove = xmove;
    x= 0;
    y = 0;
    while(!(xmove == 0 && ymove == 0)){
       cin>>xmove>>ymove;
       if(!(xmove == 0 && ymove == 0)){
       x+= xmove;
       y += ymove;
       if(x<0) x = 0;
       if(x>c) x = c;
       if(y < 0) y = 0;
       if(y > r) y = r;
       cout<<x<<" "<<y<<endl;
       }
    }
    return 0;
}