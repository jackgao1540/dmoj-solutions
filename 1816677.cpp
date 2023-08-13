#include <bits/stdc++.h>

using namespace std;

long n, t, gen[100001], nextgen[100001];
string s;

void nextGeneration(int k) {
  int p1 = ((long)1<<k) % n;
  int p2 = (n-p1) % n;
  for(int i = 0; i < n; ++i)
    nextgen[i] = gen[(i + p1) % n] ^ gen[(i + p2) % n];
  for(int i = 0; i < n; ++i)
    gen[i] = nextgen[i];
}

int main() {
  cin >> n >> t;
  cin >> s;
  for(int i = 0; i < n; ++i)
    gen[i] = s[i] - '0';
  for(int i = 60; i >= 0; --i)
    if((t >> i) & 1)
      nextGeneration(i);
  for(int i = 0; i < n; ++i)
    cout << gen[i];
}