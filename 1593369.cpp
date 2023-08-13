#include <bits/stdc++.h> 
using namespace std; 

long max(long a, long b){
  return a > b ? a : b;
}

void sieve(long limit, vector<long>& prime) 
{ 
    bool m[limit + 1]; 
    memset(m, false, sizeof(m)); 

    for (long i = 2; i <= limit; ++i) { 
        if (m[i] == false) { 
            prime.push_back(i); 
            for (int j = i; j <= limit; j += i) 
                m[j] = true; 
        } 
    } 
} 
long numPrimes(long l, long r) 
{ 
    long limit = floor(sqrt(r)) + 1; 
    vector <long> prime; 
    sieve(limit, prime); 
    long n = r - l + 1; 
    bool m[n + 1]; 
    memset(m, false, sizeof(m)); 
    for (long i = 0; i < prime.size(); i++) { 
        long lim = floor(l / prime[i]) * prime[i]; 
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
    long low, high;
    cin >> low >> high;
    cout << numPrimes(max(low, 2), high- 1) << endl;
    return 0; 
}