#include <bits/stdc++.h>

using namespace std;

string output(char c){
    if(c == 'L')return "RIGHT";
    return "LEFT";
}

int main() {
    vector <string> names; vector <char> dir;
    names.push_back("HOME");
    while(true){
        char c;
        string s;
        cin >> c >> s;
        dir.push_back(c);
        if(s.compare("SCHOOL") == 0)break;
        names.push_back(s);
    }
    for(int i = dir.size() - 1; i >= 0; i--){
        if(i == 0){
            cout << "Turn " << output(dir[i]) << " into your HOME.\n";
        }else{
            cout << "Turn " << output(dir[i]) << " onto " << names[i] << " street.\n";
        }
    }
    return 0;
}