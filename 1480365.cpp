#include <bits/stdc++.h>

using namespace std;

long long GCD(long long a, long long b){
    long long tmp = b;
    a = max(a, tmp);
    b = min(a, tmp);
    if(a % b == 0)return b;
    else return GCD(b, a % b);
}

int main() {
    long long a, b, k;
    cin >> a >> b >> k;
    long long gcd = GCD(max(a, b), min(a, b));
    //cout << "GCD: " << gcd << endl;
    //find k-th largest divisor of gcd
    vector <long long> factors;
    for(int i = 1; i <= sqrt(gcd); i++){
        if(gcd % i == 0){
            factors.push_back(i);
            if(gcd/i != i)factors.push_back(gcd/i);
        }
    }
    sort(factors.begin(), factors.end());
    //for(int i = 0; i < factors.size(); i++)cout << factors[i] << ", ";
    //cout << endl;
    cout << factors[factors.size() - k] << endl;
    return 0;
}