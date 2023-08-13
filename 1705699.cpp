#include <bits/stdc++.h>

using namespace std;

const int MM = 1e5+2;
struct node{int l, r, v, g, f;} seg[3*MM];
int n, a[MM], m;

void push_up(int id){
  seg[id].v = min(seg[2 * id].v, seg[2 * id + 1].v);
  seg[id].g = __gcd(seg[2 * id].g, seg[2 * id + 1].g);
  seg[id].f = 0;
  if(seg[id].g == seg[2 * id].g)seg[id].f += seg[2 *id].f;
  if(seg[id].g == seg[2 * id + 1].g)seg[id].f += seg[2 * id + 1].f;
 }

void build(int l, int r, int id){
  seg[id].l = l; seg[id].r = r;
  if(l == r){seg[id].v = seg[id].g = a[l]; seg[id].f = 1; return;}
  int mid = (seg[id].l + seg[id].r)/2;
  build(l, mid, 2 * id);
  build(mid + 1, r, 2 * id + 1);
  push_up(id);
}

void update(int pos, int val, int id){
  if(seg[id].l == pos && seg[id].r == pos){
    seg[id].v = seg[id].g = val;
    return;
  }
  int mid = (seg[id].l + seg[id].r)/2;
  if(pos <= mid){
    update(pos, val, 2 * id);
  }else update(pos,val,2*id+1);
  push_up(id);
}

int qryMin(int l, int r, int id){
  if(seg[id].l == l && seg[id].r == r)return seg[id].v;
  int mid = (seg[id].l + seg[id].r)/2;
  if(r <= mid)return qryMin(l, r, 2 * id);
  if(l > mid)return qryMin(l, r, 2 * id + 1);
  return min(qryMin(l, mid, 2 * id), qryMin(mid + 1, r, 2 * id + 1));
}

int qryGcd(int l, int r, int id){
  if(seg[id].l == l && seg[id].r == r)return seg[id].g;
  int mid = (seg[id].l + seg[id].r)/2;
  if(r <= mid)return qryGcd(l, r, 2 * id);
  if(l > mid)return qryGcd(l, r, 2 * id + 1);
  return __gcd(qryGcd(l, mid, 2 * id), qryGcd(mid + 1, r, 2 * id + 1));
}

int qryCnt(int l, int r, int g, int id){
  if(seg[id].l == l && seg[id].r == r)return seg[id].g == g ? seg[id].f : 0;
  int mid = (seg[id].l + seg[id].r)/2;
  if(r <= mid)return qryCnt(l, r, g, 2 * id);
  if(l > mid)return qryCnt(l, r, g, 2 * id + 1);
  return qryCnt(l, mid, g, 2 * id) + qryCnt(mid + 1, r, g, 2 * id + 1);
}

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= n; i++){
    scanf("%d", &a[i]);
  }
  build(1, n, 1);
  for(int i = 1, x, y; i <= m; i++){
    char op;
    scanf(" %c %d%d", &op, &x, &y);
    if(op == 'C')update(x, y, 1);
    if(op == 'M')printf("%d\n", qryMin(x, y, 1));
    if(op == 'G')printf("%d\n", qryGcd(x, y, 1));
    if(op == 'Q')printf("%d\n", qryCnt(x, y, qryGcd(x, y, 1), 1));
  }
}