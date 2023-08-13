#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin>>s;
while(s != "quit!"){
    //do shit
    string r = s;
    if(s.size() >= 4){
    //can edit if last two == or
        if(s[s.size() - 2] == 'o' && s[s.size() - 1] == 'r' && s[s.size() - 3] != 'a'&& s[s.size() - 3] != 'e'&& s[s.size() - 3] != 'i'&& s[s.size() - 3] != 'o'&& s[s.size() - 3] != 'u'){
        r[s.size() - 1] = 'u';
        r += 'r';
        }
    }
    cout<<r<<endl;
    cin>>s;
}
    return 0;
}