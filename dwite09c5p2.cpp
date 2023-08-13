#include <iostream>

using namespace std;

int isPrime[100] = {0};

int main() {
  isPrime[2] = isPrime[3] =  isPrime[5] = isPrime[7] = isPrime[11] =  isPrime[13] = isPrime[17] = isPrime[19] = isPrime[23] = isPrime[29] = isPrime[31] = isPrime[37] =  isPrime[41] = isPrime[43] =  isPrime[47] = isPrime[53] =  isPrime[59] =  isPrime[61] = isPrime[ 67] =  isPrime[71] =  isPrime[73] =  isPrime[79] =  isPrime[83] =  isPrime[89] =  isPrime[97] = 1;
  for(int k = 0; k < 5; k++){
    int n; 
    cin >> n;
    bool foundLeft = false, foundRight = false;
    int left, right;
    //find first prime on the left 
    for(int i = n - 1; i > 1; i--){
      if(isPrime[i]){
        if(!foundLeft){
          foundLeft = 1;
          continue;
        }else{
          left = i;
          break;
        }
      }
    }
    //find first prime on the right
    for(int i = n + 1; i < 999; i++){
      if(isPrime[i]){
        if(!foundRight){
          foundRight = 1;
          continue;
        }else{
          right = i;
          break;
        }
      }
    }
    //find the min difference
    if(n - left == right - n){
      //take right
      cout << right << endl;
    }else if(n - left < right - n){
      //left
      cout << left << endl;
    }else{
      //right
      cout << right << endl;
    }
  }
}