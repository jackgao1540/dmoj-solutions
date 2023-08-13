#include <bits/stdc++.h>

using namespace std;

int main() {
    string s, newS = "";
    getline(cin, s);
    bool isUpper = true;
    for(int i = 0; i < s.size(); i++){
        if('A' <= s[i] && s[i] <= 'Z'){
            //is a letter
            if(s[i] == 'I' && (i == 0 || s[i - 1] == ' ' || s[i - 1] == '.') && (i == s.size() - 1 || s[i + 1] == ' ' || s[i + 1] == '.')){
                if(isUpper)isUpper = false;
                newS += s[i];
            }else{
                if(isUpper){
                    isUpper = false;
                    newS += s[i];
                }else newS += tolower(s[i]);
            }
        }else{
            if(isUpper && s[i] != ' ' && s[i] != '.'){
              isUpper = false;
            }else if(s[i] == '.')isUpper = true;
            newS += s[i];
        }
    }
    cout << newS;
    return 0;
}