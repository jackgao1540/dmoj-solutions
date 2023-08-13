#include<iostream>
#include <string>

using namespace std; 

int min(int a, int b) 
{ return a < b ? a : b; } 
  
int dp[2][5001] = {0};

void flip(){
  for(int i = 0; i < 5001; i++){
    dp[1][i] = dp[0][i];
    dp[0][i] = 0;
  }
}

/*
int findMinInsertions(string str, int l, int h) 
{ 
    // Base Cases 
    if(dp[l][h] != 0)return dp[l][h];
    if (l > h) return 99999999; 
    if (l == h) return dp[l][h] = 0; 
    if (l == h - 1) return dp[l][h] =(str[l] == str[h])? 0 : 1; 
  
    return dp[l][h] = ((str[l] == str[h])?  findMinInsertions(str, l + 1, h - 1): (min(findMinInsertions(str, l, h - 1), findMinInsertions(str, l + 1, h)) + 1)); 
} */

int main() 
{ 
    int n;
    cin >> n;
    string str;
    cin >> str;
    //dp
    for(int l = n - 1; l >= 0; l--){
      for(int r = l; r < n; r++){
        if(l == r){
          dp[0][r] = 0;
        }else if(l + 1 == r){
          if(str[l] == str[r]){
            dp[0][r] = 0;
          }else dp[0][r] = 1;
        }else
        if(str[l] == str[r]){
          //l = 0
          dp[0][r] = dp[1][r - 1];
        }else{
          dp[0][r] = min(dp[1][r], dp[0][r -1]) + 1;
        }
      }
      flip();

    }
    cout << dp[1][n - 1];
    return 0; 
}