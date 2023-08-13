#include <bits/stdc++.h>

using namespace std;

const int MM = 1e5 + 5;
int nfactors[MM], t, l, r, k;
vector <int> arr[MM];

int main(){
  //fill up factor table
  for(int i = 0; i < MM; i++)nfactors[i] = 2;
  nfactors[1] =1;
  for(int i = 2; 2 * i < MM; i++){
    for(int j = 2 * i; j < MM; j += i)nfactors[j]++;
  }
  for(int i = 1; i < MM; i++){
    arr[nfactors[i]].push_back(i);
  }
  scanf("%d", &t);
  for(int i = 0; i < t; i++){
    scanf("%d%d%d",&k, &l, &r);
    int left = lower_bound(arr[k].begin(), arr[k].end(), l) - arr[k].begin();
    int right = upper_bound(arr[k].begin(), arr[k].end(), r) - arr[k].begin();
    printf("%d\n", right - left);
  }
}

/*
const int MM = 10 + 5;
int factors[MM], numFactors[MM];

void calculateFactors(){
  for(int i = 0; i < MM; i++)factors[i] = i;
  factors[1] = 1;
  factors[2] = 2;
  factors[3] = 3;
  for(int i = 4; i < MM; i += 2)factors[i] = 2;
  for(int i = 5; i < MM; i++){
    if(factors[i] == i){
      for(int j = i * i; j < MM; j += i)factors[j] = min(factors[j], i);
    }
  }
}

int main() {
  //use sieve to precompute the # of factors from 1 to MM
  calculateFactors();
  //factors of 1 is 1, 2 is 1, 3 is 1
  numFactors[1] = 1;
  numFactors[2] = 2;
  numFactors[3] = 2;
  for(int i = 4; i < MM; i++){
    //count number of factors of this number 
    int curNum = i, minFactor = factors[i], ans = 1;
    //cout << "minimum prime factor of " << i << " is " << factors[i] << endl;
    while(curNum != 1){
      if(curNum == minFactor){
        ans *= 2; break;
      }
      int c = 1; //number of times minFactor goes into curNum 
      curNum /= minFactor;
      while(curNum % minFactor == 0){
        c += 1;
        curNum /= minFactor;
      }
      ans *= (c + 1);
      minFactor = factors[curNum];
    }
    numFactors[i] = ans;
    //cout << "number of factors of " << i << " is: " << ans << endl;
  }
  int t;
  scanf("%d",&t);
  for(int i = 0; i < t; i++){
    int l, r, k;
    scanf("%d%d%d", &k, &l, &r);
    
  }
}*/