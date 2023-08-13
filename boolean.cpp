#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    int found;
    int pos = -1;
    int numnot = 0;
    bool reverse = false;
    getline(cin, s);
    while(found != string::npos){
        found = s.find("not", pos + 1);
        if(found != string::npos) {
            pos = found;
            numnot = numnot + 1;
        }
    }
    if(numnot%2){
        reverse = 1;
    }
    if(s.find("True") != string::npos){
        if(reverse) cout<< "False"; else cout<<"True";
    }else{
          if(reverse) cout<< "True"; else cout<<"False";
    }
    return 0;
}