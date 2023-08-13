#include <bits/stdc++.h>

using namespace std;

string convTo3(int a){
  string ans = "";
  int d = a;
  while(d >= 3){
    ans += (d % 3) + '0';
    d /= 3;
  }
  ans += (d + '0');
  for(int i = 0; i < ans.size()/2; i++){
    char tmp = ans[i];
    ans[i] = ans[ans.size() - i - 1];
    ans[ans.size() - i - 1] = tmp;    
  }
  return ans;
}

int main() {
  string a, b;
  cin >> a >> b;
  unsigned int sum = 0;
  for(int i = 0; i < a.size(); i++){
    sum += ((a[i] - '0') << (a.size() - 1 - i));
  }
  //cout << "sum: " << sum << endl;
  for(int i = 0; i < a.size(); i++){
    char ch = a[i];
    char newC;
    if(ch == '0')newC = '1';
    else newC = '0';
    int newSum = sum - ((ch - '0') << (a.size() - 1 - i)) + ((newC - '0') << (a.size() - 1 - i));
    //cout << newSum << ' ';
    //see if newSum has one bit in common with b 
    int numDiff = 0;
    string c = convTo3(newSum);
    if(c.size() == b.size()){for(int i = 0; i < c.size(); i++){
      if(c[i] != b[i])numDiff++;
    }
    //cout << c << ' ' << numDiff << endl;
    if(numDiff == 1){cout << newSum << endl;return 0;}
    }else continue;
  }
}