#include <iostream> 
using namespace std; 
  
// Iterative DP function to find the number of times 
// the second string occurs in the first string, 
// whether continuous or discontinuous 
long long count(string a, string b) 
{ 
    long long m = a.length(); 
    long long n = b.length(); 
  
    // Create a table to store results of sub-problems 
    long long lookup[m + 1][n + 1] = { { 0 } }; 
  
    // If first string is empty 
    for (long long i = 0; i <= n; ++i) 
        lookup[0][i] = 0; 
  
    // If second string is empty 
    for (long long i = 0; i <= m; ++i) 
        lookup[i][0] = 1; 
  
    // Fill lookup[][] in bottom up manner 
    for (long long i = 1; i <= m; i++) 
    { 
        for (long long j = 1; j <= n; j++) 
        { 
            // If last characters are same, we have two  
            // options - 
            // 1. consider last characters of both strings 
            //    in solution 
            // 2. ignore last character of first string 
            if (a[i - 1] == b[j - 1]) 
                lookup[i][j] = lookup[i - 1][j - 1] +  
                               lookup[i - 1][j]; 
                  
            else
                // If last character are different, ignore 
                // last character of first string 
                lookup[i][j] = lookup[i - 1][j]; 
        } 
    } 
  
    return lookup[m][n]; 
} 
  
// Driver code 
int main() 
{ 
    string a;
    string b = "love"; 
    cin >> a;
    cout << count(a, b); 
  
    return 0; 
}