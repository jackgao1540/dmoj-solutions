#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    int found1, found2, pos1, pos2;
    pos1 = -1;
    pos2 = -1;
    int numhappy = 0;
    int numsad = 0;

        while(found1 != string::npos){
            found1 = s.find(":-)", pos1 + 1);
            if(found1 != string::npos){
                numhappy++;
                pos1 = found1;
            }
        }
        while(found2 != string::npos){
           found2 = s.find(":-(", pos2 + 1); 
              if(found2 != string::npos){
                numsad++;
                pos2 = found2;
            }
        }
    
    if(numhappy>numsad) cout<<"happy";
     if(numhappy<numsad) cout<<"sad";
     if(numhappy==numsad && numhappy!= 0 && numsad != 0) cout<<"unsure";
     if(numhappy == 0 && numsad == 0) cout<<"none";
    return 0;
}