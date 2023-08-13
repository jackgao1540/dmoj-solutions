#include <iostream>

using namespace std;

int main(){
    double vin;
    double rin;
    double rout;
    cin>>vin;
    cin>>rin;
    cin>>rout;
    cout << vin * (1 + (rin/rout));
    return 0;
}