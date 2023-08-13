#include <bits/stdc++.h> 
using namespace std; 
typedef pair <int, int> pii;
const int MM = 1000002;
int N, bit[MM], x[MM], y[MM], rk[MM], id[MM], cnt;
char op[MM];
vector <pii> vec;

void update(int pos, int v){
  for(int x = pos; x <= N; x+=x&-x){
    bit[x] += v;
  }
}

int find_kth(int k){
  int ans = 0, cnt = 0;
  for(int i = 20; i >= 0; i--){
    ans += (1<<i);
    if(ans >= N || cnt + bit[ans] >= k)ans -= (1<<i);
    else cnt += bit[ans];
  }
  return ans + 1;
}

int main(){
  scanf("%d", &N);
  for(int i = 1; i <= N; i++){
    scanf(" %c %d", &op[i], &x[i]);
    if(op[i] == 'Q'){
      vec.push_back(make_pair(0, i));
    }else{
      scanf("%d", &y[i]);
      vec.push_back(make_pair(y[i], i));
    }
  }
  cnt = 0;
  sort(vec.begin(), vec.end(), greater <pii>());
  for(auto e: vec)rk[e.second] = ++cnt;
  for(int i = 1; i <= N; i++){
    if(op[i] == 'N'){
      update(rk[i], 1);
      id[rk[i]] = x[i];
      y[x[i]] = rk[i];
    }else if(op[i] == 'M'){
      update(y[x[i]], -1);
      update(rk[i], 1);
      id[rk[i]] = x[i];
      y[x[i]] = rk[i];
    }else{
      printf("%d\n", id[find_kth(x[i])]);
    }
  }
}