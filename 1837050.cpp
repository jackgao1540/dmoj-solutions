#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e6 + 3;
int N, K, a[MM], pmx[MM], smx[MM], day[MM]; ll dp[MM], t1[MM], t2[MM];
int main(){
	cin >> N >> K;
	for(int i = 1; i <= N; i++){
		cin >> a[i];
		day[i] = (i + K - 1)/K;
		if(day[i] != day[i - 1])pmx[i] = a[i];
		else pmx[i] = max(pmx[i - 1], a[i]);
	}
	for(int i = N; i >= 1; i--){
		if(day[i] != day[i + 1])smx[i] = a[i];
		else smx[i] = max(smx[i + 1], a[i]);
	}
	for(int i = 1; i <= K; i++) dp[i] = pmx[i];
	for(int i = 2; i <= day[N]; i++){
		int fst = (i - 2)*K + 1, first = (i - 1)*K;
		for(int j = first; j >= fst; j--){
			t1[j] = dp[j] + (j == first ? 0 : smx[j + 1]);
			t2[j] = dp[j];
			if(j != first){
				t1[j] = max(t1[j + 1], t1[j]);
				t2[j] = max(t2[j + 1], t2[j]);
			}
		}
		for(int j = first + 1; j <= min(i*K, N); j++){
			dp[j] = max(t1[j - K], t2[j - K] + pmx[j]);
		}	
	}
	cout << dp[N] << '\n';
}