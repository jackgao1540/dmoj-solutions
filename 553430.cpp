#include <bits/stdc++.h>

using namespace std;

int main() {
    int area;
    cin>>area;
    int perim = 0;
    int a = sqrt(area); a++;
    int found = 0;
    while(!found){
        if ((area % a) == 0){
            found = 1;
            perim = 2*(a + (area / a)); 
        }else{
            a--;
            }
    }
    cout<<perim;
    return 0;
}