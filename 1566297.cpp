#include <iostream> 
using namespace std; 
  
long long f(string s) 
{ 
    string b = "DMOJ";
    long long m = s.length(); 
    long long n = b.length(); 
    long long lookup[m + 1][n + 1] = { { 0 } }; 
    for (long long i = 0; i <= n; ++i) 
        lookup[0][i] = 0; 
    for (long long i = 0; i <= m; ++i) 
        lookup[i][0] = 1; 
    for (long long i = 1; i <= m; i++) 
    { 
        for (long long j = 1; j <= n; j++) 
        { 
            if (s[i - 1] == b[j - 1]) 
                lookup[i][j] = lookup[i - 1][j - 1] +  
                               lookup[i - 1][j]; 
                  
            else
                lookup[i][j] = lookup[i - 1][j]; 
        } 
    } 
  
    return lookup[m][n]; 
} 

int main() 
{ 
    return 0; 
}