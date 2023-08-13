#include <bits/stdc++.h> 
using namespace std; 

int max(int a, int b){
  return a > b ? a : b;
}

void sieve(int limit, vector<int>& prime) 
{ 
    bool m[limit + 1]; 
    memset(m, false, sizeof(m)); 

    for (int i = 2; i <= limit; ++i) { 
        if (m[i] == false) { 
            prime.push_back(i); 
            for (int j = i; j <= limit; j += i) 
                m[j] = true; 
        } 
    } 
} 
int numPrimes(int l, int r) 
{ 
    int limit = floor(sqrt(r)) + 1; 
    vector <int> prime; 
    sieve(limit, prime); 
    int n = r - l + 1; 
    bool m[n + 1]; 
    memset(m, false, sizeof(m)); 
    for (int i = 0; i < prime.size(); i++) { 
        int lim = floor(l / prime[i]) * prime[i]; 
        if (lim < l) 
            lim += prime[i]; 
        if(lim==prime[i]) 
            lim += prime[i]; 
        for (long j = lim; j <= r; j += prime[i]) 
            m[j - l] = true; 
    }  
    long c = 0;
    for (long i = l; i <= r; i++) 
        if (!m[i - l]) 
            c++;
    return c;
} 
  
int main() 
{ 
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){int low, high;
    cin >> low >> high;
    cout << numPrimes(max(low, 2), high- 1) << endl;
    }
    return 0; 
}