#include <bits/stdc++.h>

using namespace std;

int main() {
    char number[12];
    cin>>number;
    int numbers[10];
    int c = 0;
    for(int i = 0; i < 12; i++){
        if(number[i] != 45) {
            numbers[c] = (int)number[i] - 48;
            c++;
        }
    }
    c = numbers[6] + numbers[7] + numbers[8] + numbers[9];
    int a = numbers[1] + numbers[0] + numbers[2];
    int b = numbers[3]  + numbers[4] + numbers[5];
    if(a == b && b == c && a == c)cout<<"Goony!"; else cout<<"Pick up the phone!";
    return 0;
}