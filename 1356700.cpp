#include <bits/stdc++.h>

using namespace std;

bool isI(string s, int i){
  if(s[i] == 'I'){
    if(i == s.size() - 1 || s[i + 1] == ' '){
      if(i == 0 || s[i - 1] == ' ')return true;
      else return false;
    }else return false;
  }else return false;
}

int main() {
    string s;
    string newS = "";
    getline(cin, s);
    bool isFirst = true;
    for(int i = 0; i < s.size(); i++){
        if((isFirst == true && s[i] != ' ' && s[i] >= 'A' && s[i] <= 'Z') || isI(s, i)){
            isFirst = false;
            char c = (s[i]);
            newS += c;
        }else{
           newS += tolower(s[i]);
           if((s[i] < 'A' || s[i] > 'Z')&&s[i] != ' ')isFirst = false;
           if(s[i] == '.')isFirst = true;
        }
    }
    cout << newS;
    return 0;
}