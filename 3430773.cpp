#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cout << "Ready" << endl;
    getline(cin, s);
    while(s.size() == 2){
        //cout << s << endl;
        char a = s[0], b = s[1];
        if(a == ' ' || b == ' ')return 0;
        if((a == 'p' && b == 'q')||(a == 'q' && b == 'p')||(a == 'b' && b == 'd')||(a == 'd' && b == 'b')){
            cout << "Mirrored pair" << endl;
        }else cout << "Ordinary pair" << endl;
        getline(cin, s);
    }
    return 0;
}