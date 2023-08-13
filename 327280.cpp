#include <iostream>

using namespace std;

int main(){
    int minf;
    string ForB;
    int mdif;
    cin>>minf;
    cin>>ForB;
    cin>>mdif;
    if (ForB == "Infront"){
         cout << minf - mdif;
    }else cout << minf + mdif;

    return 0;
}