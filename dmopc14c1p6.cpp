#include <bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
const int inf = 0x3f3f3f3f3f3f3f3f;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
typedef pair<double, double> pdd;
typedef complex<int> point;
typedef complex<double> fpoint;
#define X real()
#define Y imag()
template <typename T>
constexpr inline T lg(T x) {
  return sizeof(T) * 8 - (sizeof(T) > 4 ? __builtin_clzll(x) : __builtin_clz(x)) - is_signed<T>::value;
}
ostream& operator<<(ostream &output, const pii &p) {cout << '(' << p.first << "," << p.second << ')';return output;}
ostream& operator<<(ostream &output, const pdd &p) {cout << '(' << p.first << "," << p.second << ')';return output;}
template <typename T>constexpr const inline T& _max(const T& x, const T& y) {return x<y?y:x;}
template <typename T>constexpr const inline T& _min(const T& x, const T& y) {return x<y?x:y;}
template <typename T, typename ...S>constexpr const inline T& _max(const T& m, const S&...s) {return _max(m, _max(s...));}
template <typename T, typename ...S>constexpr const inline T& _min(const T& m, const S&...s) {return _min(m, _min(s...));}
#define max(...) _max(__VA_ARGS__)
#define min(...) _min(__VA_ARGS__)

int freq[126][126];
map<multiset<int>, int> sequence_to_id;
vector<multiset<int>> unique_sequences;

int N, K, S, T;

double transition[126][126];
double orig_transition[126][126];
double result[126][126];

void matmult() {
  for (int r = 0; r < S; ++r) {
    for (int c = 0; c < S; ++c) {
      double ans = 0;
      for (int k = 0; k < S; ++k) {
        ans += transition[r][k] * transition[k][c];
      }
      result[r][c] = ans;
    }
  }

  for (int i = 0; i < S; ++i) {
    for (int j = 0; j < S; ++j) {
      transition[i][j] = result[i][j];
    }
  }
}

void matmultorig() {
  for (int r = 0; r < S; ++r) {
    for (int c = 0; c < S; ++c) {
      double ans = 0;
      for (int k = 0; k < S; ++k) {
        ans += transition[r][k] * orig_transition[k][c];
      }
      result[r][c] = ans;
    }
  }

  for (int i = 0; i < S; ++i) {
    for (int j = 0; j < S; ++j) {
      transition[i][j] = result[i][j];
    }
  }
}

void matexp(int n) {
  for (int i = lg(n) - 1; i >= 0; --i) {
    matmult();
    if (n&(1LL<<i)) matmultorig();
  }
}

void generate_sequences(multiset<int> seq, bool gen_id, vector<multiset<int>> &seq_list) {

  multiset<multiset<int>> poss_seq;
  if (K > 1) {
    for (auto it1 = seq.begin(); it1 != seq.end(); ++it1) {
      for (auto it2 = seq.begin(); it2 != seq.end(); ++it2) {
        poss_seq.insert(multiset<int>{*it1, *it2});
      }
    }

    if (K == 4 || K == 5) {
      multiset<multiset<int>> poss;
      for (auto it1 = poss_seq.begin(); it1 != poss_seq.end(); ++it1) {
        for (auto it2 = poss_seq.begin(); it2 != poss_seq.end(); ++it2) {
          poss.insert(multiset<int>{*(it1->begin()), *(it1->rbegin()), *(it2->begin()), *(it2->rbegin())});
        }
      }
      poss_seq = move(poss);
    }
  }

  if (K & 1) {
    multiset<multiset<int>> poss;
    for (auto it1 = poss_seq.begin(); it1 != poss_seq.end(); ++it1) {
      multiset<int> cur = *it1;
      for (auto it2 = seq.begin(); it2 != seq.end(); ++it2) {
        multiset<int> toinsert(cur);
        toinsert.insert(*it2);
        poss.insert(toinsert);
      }
    }

    poss_seq = move(poss);
  }

  if (gen_id) seq_list = vector<multiset<int>>(poss_seq.begin(), poss_seq.end());
  else {
    for (auto it = poss_seq.begin(); it != poss_seq.end(); ++it) {
      ++freq[sequence_to_id[seq]][sequence_to_id[*it]];
    }
    // for_each(poss_seq.begin(), poss_seq.end(), [](const multiset<int> &m){copy(m.begin(), m.end(), ostream_iterator<int>(cout, " ")); cout << '\n';});
  }

  
}

void assign_sequence_ids() {
  multiset<int> seq;
  for (int i = 1; i <= K; ++i) seq.insert(i);
  generate_sequences(seq, true, unique_sequences);
  T = unique_sequences.size();
  sort(unique_sequences.begin(), unique_sequences.end());
  unique_sequences.resize(distance(unique_sequences.begin(), unique(unique_sequences.begin(), unique_sequences.end())));
  for (uint i = 0; i < unique_sequences.size(); ++i) sequence_to_id[unique_sequences[i]] = i;
}

void generate_sequences(multiset<int> seq) {
  vector<multiset<int>> _;
  generate_sequences(seq, false, _);
}
#undef int
int main()
#define int long long
{

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  scan(K); scan(N);
  if (K == 1) {cout << 1; return 0;}
  assign_sequence_ids();

  for (const multiset<int> &m : unique_sequences) {
    generate_sequences(m);
  }

  S = unique_sequences.size();
  for (int i = 0; i < S; ++i) {
    for (int j = 0; j < S; ++j) {
      orig_transition[i][j] = transition[i][j] = freq[i][j] / static_cast<double>(T);
    }
  }

  if (N == 0) {for (int i = 0; i < S-1; ++i) cout << "0\n"; cout << "1\n"; return 0;}

  matexp(N);
  multiset<int> seq;
  vector<double> v;
  for (int i = 1; i <= K; ++i) seq.insert(i);
  for (int i = 0; i < S; ++i) v.push_back(transition[sequence_to_id[seq]][i]);
  sort(v.begin(), v.end());
  for (double d : v) {
    cout << setprecision(50) << fixed << d << '\n';
  }
  cout << _;
}