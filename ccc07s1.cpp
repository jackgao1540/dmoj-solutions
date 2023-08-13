#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;
    const int year = 2007;
    const int month = 2;
    const int day = 27;
    int dy, dd, dm;
    for(int i =0; i<n; i++){
      cin>>dy>>dm>>dd;  
      if(year - dy > 18){
          cout<<"Yes";
      }else if (year - dy == 18){
          if(month - dm > 0){
              cout<<"Yes";
          }else if (month - dm == 0){
              if(day - dd > 0){
                  cout<<"Yes";
              }else if(day - dd == 0){
                  cout<<"Yes";
              }else cout<<"No";
          }else{
              cout<<"No";
          }
      }else cout<<"No";
      cout<<endl;
    }
    return 0;
}