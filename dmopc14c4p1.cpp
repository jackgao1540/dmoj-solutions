#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin>>s;
    for(int i = 0; i < s.size(); i++){
        if(48 <= s[i]  && s[i] <= 57){
            s[i] += 17;
            if(s[i] == 65) s[i] = 57; else s[i] -= 1;
        }else if(65 <= s[i] && s[i] <= 80){
            s[i] += 10;
            s[i] -= 1;
        }
        //converted
    }
    cout<<s;
    return 0;
}