#include <bits/stdc++.h>
using namespace std;
 
#define alias_gen(type, from, to) template<typename... Ts>decltype(type<T...>().from(std::declval<Ts>()...)) to(Ts...s) {return this->from(s...);}
#define iterator_aliases(alias) alias(begin, b); alias(end, e); alias(rbegin, rb); alias(rend, re); alias(cbegin, cb); alias(cend, ce); alias(crbegin, crb); alias(crend, cre);
#define ordered_aliases(alias) alias(insert, ins); alias(erase, ers); alias(clear, cl); alias(lower_bound, lb); alias(upper_bound, ub); alias(equal_range, eqr); alias(find, f); alias(count, c);
#define capacity_aliases(alias) alias(empty, mt); alias(size, s); alias(max_size, ms);
 
template<typename ...T>
struct _vector : public vector<T...> {
  #define al(from, to) alias_gen(vector, from, to)
  iterator_aliases(al);
  capacity_aliases(al);
  al(push_back, pb);
  al(pop_back, ppb);
  al(resize, rs);
  al(front, f);
  al(back, bk);
  al(clear, cl);
  #undef al
};
#define vector _vector
 
template<typename ...T>
struct _complex : public complex<T...> {
  #define al(from, to) alias_gen(complex, from, to)
  al(real, x);
  al(imag, y);
  #undef al
};
#define complex _complex
 
template<typename ...T>
struct _set : public set<T...> {
  #define al(from, to) alias_gen(set, from, to)
  iterator_aliases(al);
  ordered_aliases(al);
  capacity_aliases(al);
  #undef al
};
#define set _set
 
template<typename ...T>
struct _multiset : public multiset<T...> {
  #define al(from, to) alias_gen(multiset, from, to)
  iterator_aliases(al);
  ordered_aliases(al);
  capacity_aliases(al);
  #undef al
};
#define multiset _multiset
 
template<typename ...T>
struct _map : public map<T...> {
  #define al(from, to) alias_gen(map, from, to)
  iterator_aliases(al);
  ordered_aliases(al);
  capacity_aliases(al);
  #undef al
};
#define map _map
 
template<typename ...T>
struct _multimap : public multimap<T...> {
  #define al(from, to) alias_gen(multimap, from, to)
  iterator_aliases(al);
  ordered_aliases(al);
  capacity_aliases(al);
  #undef al
};
#define multimap _multimap
 
template<typename ...T>
struct _stack : public stack<T...> {
  #define al(from, to) alias_gen(stack, from, to)
  al(empty, mt);
  al(size, s);
  al(top, t);
  al(push, p);
  al(pop, pp);
  #undef al
};
#define stack _stack
 
template<typename ...T>
struct _queue : public queue<T...> {
  #define al(from, to) alias_gen(queue, from, to)
  al(empty, mt);
  al(size, s);
  al(front, f);
  al(back, b);
  al(push, p);
  al(emplace, e);
  al(pop, pp);
  #undef al
};
#define queue _queue
 
template<typename ...T>
struct _priority_queue : public priority_queue<T...> {
  #define al(from, to) alias_gen(priority_queue, from, to)
  al(empty, mt);
  al(size, s);
  al(top, t);
  al(push, p);
  al(emplace, e);
  al(pop, pp);
  #undef al
};
#define priority_queue _priority_queue
 
__attribute__((always_inline)) inline void cppinput() {ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
__attribute__((always_inline)) inline int gc() {return getchar_unlocked();}
__attribute__((always_inline)) inline int pc(int c) {return putchar_unlocked(c);}
char _;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
typedef pair<double, double> pdd;
typedef complex<int> point;
typedef complex<double> fpoint;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int iinf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
template <typename T>__attribute__((always_inline)) inline T lg(T x){return sizeof(T)*8-(sizeof(T)>4?__builtin_clzll(x):__builtin_clz(x))-is_signed<T>::value;}
template <typename T>__attribute__((always_inline)) inline void scan(T& x){char _,_n;while((_n=gc())<45);if(_n-45)x=_n;else x=gc();for(x-=48;47<(_=gc());x=(x<<3)+(x<<1)+_-48);if(_n<46)x=-x;}
template <typename T, typename ...S>void scan(T& m, S&...s) {scan(m); scan(s...);}
ostream& operator<<(ostream &output, const pii &p) {cout << '(' << p.first << "," << p.second << ')';return output;}
ostream& operator<<(ostream &output, const pdd &p) {cout << '(' << p.first << "," << p.second << ')';return output;}
template <typename T>__attribute__((always_inline)) constexpr const inline T& _max(const T& x, const T& y) {return x<y?y:x;}
template <typename T>__attribute__((always_inline)) constexpr const inline T& _min(const T& x, const T& y) {return x<y?x:y;}
template <typename T, typename ...S>constexpr const inline T& _max(const T& m, const S&...s) {return _max(m, _max(s...));}
template <typename T, typename ...S>constexpr const inline T& _min(const T& m, const S&...s) {return _min(m, _min(s...));}
#define max(...) _max(__VA_ARGS__)
#define min(...) _min(__VA_ARGS__)
#define grabt(type, ...) type __VA_ARGS__ ; scan(__VA_ARGS__);
#define grab(...) int __VA_ARGS__ ; scan(__VA_ARGS__);
#define nl '\n'
#define nls "\n"
template<typename T>__attribute__((always_inline)) inline void print(const T& n){T N=n;if(n<0){pc('-');N=-N;}T rev=N,count=0;if(N==0){pc('0');return;}while((rev%10)==0){++count;rev/=10;}rev=0;while(N!=0){rev=(rev<<3)+(rev<<1)+N%10;N/=10;}while(rev!=0){pc(rev%10+'0');rev/=10;}while(count)pc('0'),--count;}
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define lp_e(e) for(int _=0;_<e;++_)
#define lp_ve(v,e) for(int v=0;v<e;++v)
#define lp_vbe(v,b,e) for(int v=b;v<e;++v)
#define lpe_e(e) for(int _=0;_<=e;++_)
#define lpe_ve(v,e) for(int v=0;v<=e;++v)
#define lpe_vbe(v,b,e) for(int v=b;v<=e;++v)
#define lp(...) GET_MACRO(__VA_ARGS__, lp_vbe, lp_ve, lp_e)(__VA_ARGS__)
#define lpe(...) GET_MACRO(__VA_ARGS__, lpe_vbe, lpe_ve, lpe_e)(__VA_ARGS__)

int main() {
    grab(T);
    lp(i, T) {
        grab(N);
        stack <int> mountain;
        lp(j, N) {
            grab(x);
            mountain.p(x);
        }
        stack <int> branch;
        int next = 1;
        while(next < N + 1) {
            if(!branch.mt() && branch.t() == next){
                branch.pp();
                next++;
                continue;
            }
            if(!mountain.mt() && mountain.t() == next){
                mountain.pp();
                next++;
                continue;
            }
            //move from mountain to branch
            if(mountain.mt()){
                //no solution
                pc('N'); pc(nl);
                break;
            }
            branch.p(mountain.t());
            mountain.pp();
        }
        if(next > N) pc('Y'); pc(nl);
    }
    return 0;
}