#include <bits/stdc++.h>

using namespace std;

int main() {
    bool can_be_used = true;
    string c;
    cin>>c;
    for (int i = 0; i < c.size();i++){
        if (c[i] == 73 || c[i] == 79|| c[i] == 83|| c[i] == 72|| c[i] == 90|| c[i] == 88|| c[i] == 78){
          //it's good fam  
        }else{
            //nah
        can_be_used = false;
        }
    }
    if (can_be_used){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
    return 0;
}