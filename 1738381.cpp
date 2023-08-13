#include <bits/stdc++.h>

using namespace std;

const int MM = 100010;
static int dp[MM][2];

void build(int host, int fr, int protocol);

int findSample(int n, int confidence[], int host[], int protocol[])
{
	for(int i = 0; i < n; i++){
		dp[i][1] = confidence[i];
    dp[i][0] = 0;
  }
	for (int i = n-1; i > 0; --i)
		build(host[i], i, protocol[i]);
	
	return max(dp[0][0], dp[0][1]);
}

void build(int host, int fr, int protocol)
{
	if(protocol == 0)
	{
		dp[host][1] += dp[fr][0];
		dp[host][0] += max(dp[fr][1], dp[fr][0]);
	}
	else if(protocol == 1)
	{
		dp[host][1] = max(dp[host][1]+max(dp[fr][0], dp[fr][1]), dp[host][0]+dp[fr][1]);
		dp[host][0] += dp[fr][0];
	}
	else
	{
		dp[host][1] = max(dp[host][1] + dp[fr][0], dp[host][0] + dp[fr][1] );
		dp[host][0] += dp[fr][0];
	}
}