#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MM = 2e5 +5;
struct node{int l, r; ll lz, sum; } seg[3*MM];
int N, M, Q;

void push_up(int id){
  seg[id].sum = seg[2*id].sum + seg[2*id+1].sum;
  return;
}

void push_down(int id){
  int lc = 2*id, rc = 2*id + 1;
  seg[lc].lz += seg[id].lz;
  seg[rc].lz += seg[id].lz;
  seg[lc].sum += (ll)seg[id].lz * (ll)(seg[lc].r - seg[lc].l + 1);
  seg[rc].sum += (ll)seg[id].lz * (ll)(seg[rc].r - seg[rc].l + 1);
  seg[id].lz = 0;
}

void build(int l, int r, int id){
  seg[id].l = l; seg[id].r = r;
  if(l == r){
    scanf("%lld", &seg[id].sum);
    return;
  }
  int mid = (seg[id].l + seg[id].r)/2;
  build(l, mid, 2 * id);
  build(mid + 1, r, 2*id +1);
  push_up(id);
  return;
}

void update(int l, int r, int val, int id){
  if(seg[id].l == l && seg[id].r == r){
    seg[id].lz += val; 
    seg[id].sum += (ll)(r - l + 1) * (ll)val;
    return;
  }   
  if(seg[id].lz != 0){
    push_down(id);
  }
  int mid = (seg[id].l + seg[id].r)/2;
  if(r <= mid)update(l, r, val, 2 * id);
  else if(l > mid)update(l, r, val, 2 * id + 1);
  else{
    update(l, mid, val, 2 * id);
    update(mid + 1, r, val, 2 * id + 1);
  }
  push_up(id);
}

ll query(int l, int r, int id){
  if(seg[id].l == l && seg[id].r == r)return seg[id].sum;
  if(seg[id].lz != 0)push_down(id);
  int mid = (seg[id].l + seg[id].r)/2;
  if(r <= mid)return query(l, r, 2*id);
  else if(l > mid)return query(l, r, 2 * id + 1);
  else return query(l, mid, 2 * id) + query(mid + 1, r, 2 * id + 1);
}

int main() {
  scanf("%d%d%d", &M, &N, &Q);
  build(1, N, 1);
  for(int i = 1, op, x, y, z; i <= Q; i++){
    scanf("%d%d%d", &op, &x, &y);
    if(op == 1){
      scanf("%d", &z);
      update(x, y, z, 1);
    }else{
      printf("%lld\n", query(x, y, 1) % M);
    }
  }
}