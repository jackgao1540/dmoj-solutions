#include <bits/stdc++.h>

using namespace std;

int main() {
    int scale;
    cin>>scale;
    char screen[3*scale][3*scale];
    for(int i = 0; i < 3*scale; i++){
        for(int j = 0; j < 3*scale; j++){
            if(i < scale){
                //row 1
                if(j < scale){
                   screen[i][j] = '*'; 
                }
                if(scale <= j && j < 2* scale){
                          screen[i][j] = 'x'; 
                }
                if(2*scale <= j && j  <  3*scale){
                          screen[i][j] = '*'; 
                }
            }
            if(scale <= i && i < 2*scale){
                //row 2
                if(j < scale){
                          screen[i][j] = ' '; 
                }
                if(scale <= j  && j < 2* scale){
                          screen[i][j] = 'x'; 
                }
                if(2*scale <= j && j  <3*scale){
                          screen[i][j] = 'x'; 
                }
            }
            if( 2* scale <= i && i < 3*scale){
                //final row
                if(j < scale){
                          screen[i][j] = '*'; 
                }
                if(scale <= j  && j < 2* scale){
                          screen[i][j] = ' '; 
                }
                if(2*scale <= j && j  < 3*scale){
                         screen[i][j] = '*';  
                }
            }
        }
    }
    for(int i = 0; i < 3*scale; i++){
        for(int j = 0; j < 3*scale; j++) cout<<screen[i][j];
        cout<<endl;
    }
    return 0;
}