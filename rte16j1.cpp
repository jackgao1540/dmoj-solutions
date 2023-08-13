#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    int lCount = 0, maxL = 0, curL = 0;
    for(int i = 0; i < s.size(); i++){
        char c = s[i];
        if(c == 'L'){
          curL += 1;
          lCount++;
          //cout << curL << " " << maxL << endl;
          continue;
        }else if(c == ' '){//cout << curL << " " << maxL << endl;
        continue;
        }else{
          if(curL > maxL)maxL = curL;
          curL = 0;
        }
    }
    if(curL > maxL)maxL = curL;
    cout << lCount << " " << maxL;
    return 0;
}