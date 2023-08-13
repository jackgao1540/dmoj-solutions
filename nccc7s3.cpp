// C++ implementation of the above approach 
#include <bits/stdc++.h> 
using namespace std; 

// This function returns the required number 
// of triangles 
long long countTriangles(vector <pair<long long, long long>> P, int N) 
{ 
	// Hash Map to store the frequency of 
	// slope corresponding to a point (X, Y) 
	map<pair<long long, long long>, long long> mp; 
	long long ans = 0; 

	// Iterate over all possible points 
	for (int i = 0; i < N; i++) { 
		mp.clear(); 

		// Calculate slope of all elements 
		// with current element 
		for (int j = i + 1; j < N; j++) { 
			long long X = P[i].first - P[j].first; 
			long long Y = P[i].second - P[j].second; 

			// find the slope with reduced 
			// fraction 
			long long g = __gcd(X, Y); 
			X /= g; 
			Y /= g; 
			mp[make_pair(X, Y)]++; 
		} 
		long long num = N - (i + 1); 

		// Total number of ways to form a triangle 
		// having one point as current element 
		ans += (num * (num - 1)) / 2; 

		// Subtracting the total number of ways to 
		// form a triangle having the same slope or are 
		// collinear 
		for (auto j : mp) 
			ans -= (j.second * (j.second - 1)) / 2; 
	} 
	return ans; 
} 

// Driver Code to test above function 
int main() 
{ 
	vector <pair<long long, long long>> P;
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    long long a, b;
    cin >> a >> b;
    P.push_back(make_pair(a, b));
  }
	cout << countTriangles(P, n) << endl; 
	return 0; 
}