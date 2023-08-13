#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
typedef long long ll;
ll x0, y0, z0, x, y, z, N; set<pair<ll, pair<ll, ll>>> st;
int main(){
    cin >> x0 >> y0 >> z0 >> N;
    for(int i=1; i<=N; i++){
        cin >> x >> y >> z;
        x-=x0; y-=y0; z-=z0;
        ll g = __gcd(abs(x), __gcd(abs(y), abs(z)));
        st.insert({x/g, {y/g, z/g}});
    }
    cout << st.size() << "\n";
}