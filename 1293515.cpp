#include <iostream>
#include <cmath>

using namespace std;

int isPrime[1005] = {0};

void findPrime(int n){
  int d = sqrt(n) + 1;
  for(int i = d; i > 1; i--){
    if(n % i == 0){
      isPrime[n] = 3;
      return;
    }
  }
  isPrime[n] = 1;
  return;
}

void findSemiPrime(int n){
  //have to see if is multiple of 2 primes
  int d = sqrt(n);
  if(isPrime[n] == 0)findPrime(n);
  if(isPrime[n] == 1)return;
  for(int i = d; i > 1; i--){
    if(n % i == 0){
      if(isPrime[i] == 0)findPrime(i);
      if(isPrime[n/i] == 0)findPrime(n/i);
      if(isPrime[i] == 1 && isPrime[n/i] == 1){
        isPrime[n] = 2;
        return;
      }
    }
  }
  isPrime[n] = 3;
  return;
}

int main() {
  //0 for unchecked, 1 for prime, 2 for semiprime, 3 for composite
  isPrime[2] = isPrime[3] = isPrime[5] = isPrime[7] = isPrime[11] = isPrime[13] = isPrime[17] = isPrime[19] = isPrime[23] = 1;
  for(int k = 0; k < 5; k++){
    int n;
    cin >> n;
    findSemiPrime(n);
    cout << (isPrime[n] == 2 ? "semiprime" : "not") << endl;
  }
}