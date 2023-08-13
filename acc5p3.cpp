#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, c;

int main() {
  scanf("%d %d", &n, &c);
  vector <int> cheeses;
  long cost = 0;
  for(int i = 0, a, b; i < n; i++){
    scanf("%d %d", &a, &b);
    cost += a;
    cheeses.push_back(a - b);
  }
  sort(cheeses.begin(), cheeses.end());
  for(int i = 0; i < c; i++){
    cost -= cheeses[cheeses.size() - i - 1];
  }
  cout << cost << endl;
}