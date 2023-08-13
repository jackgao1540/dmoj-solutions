#include <bits/stdc++.h>

using namespace std;

int n;
pair<int, int> input[1001][1001];
int corners[1001], weights[1001], adj[101][101], dis[101];
bool vis[101];

int mst(int size)
{
	memset(vis, false, sizeof(vis));
	memset(dis, -1, sizeof(dis));
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	int m = 0;
	int currNode = 0;
	vis[currNode] = true;
	dis[currNode] = 0;

	for (int i = 0; i < size; i++)
	{
		if (adj[currNode][i] != -1)
			pq.push({ adj[currNode][i] ,i });
	}

	while (!pq.empty())
	{
		while (!pq.empty())
		{
			if (vis[pq.top().second])
				pq.pop();
			else
				break;
		}
		if (pq.empty()) break;
		currNode = pq.top().second;
		vis[currNode] = true;
		dis[currNode] = pq.top().first;
		m += dis[currNode];
		pq.pop();
		for (int i = 0; i < size; i++)
		{
			if (adj[currNode][i] != -1)
				pq.push({ adj[currNode][i] ,i });
		}
	}

	return m;

}

int main() {
  for (int i = 0; i < 1001; i++)
		for (int j = 0; j < 1001; j++)
			input[i][j] = { -1,0 };

	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 101; j++)
			adj[i][j] = -1;

	for (int i = 0; i < 101; i++)
		adj[i][i] = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++){
		int k;
		scanf("%d", &k);
		for (int j = 0; j < k; j++)
			scanf("%d", &corners[j]);
		for (int j = 0; j < k; j++)
			scanf("%d", &weights[j]);
		for (int j = 0; j < k; j++){
			int z = (j + 1) % k;
			if (input[corners[j]][corners[z]].second > 0){
				if (adj[i][input[corners[j]][corners[z]].first] > weights[j] || adj[i][input[corners[j]][corners[z]].first] == -1){
					adj[i][input[corners[j]][corners[z]].first] = weights[j];
					adj[input[corners[j]][corners[z]].first][i] = weights[j];
					

				}
				input[corners[z]][corners[j]].first = -1;
				input[corners[j]][corners[z]].first = -1;
			}
			else{
				input[corners[j]][corners[z]].second = weights[j];
				input[corners[z]][corners[j]].second = weights[j];
				input[corners[j]][corners[z]].first = i;
				input[corners[z]][corners[j]].first = i;

			}
		}


	}
	for (int i = 0; i < 1001; i++){
		for (int j = 0; j < 1001; j++){
			if (input[j][i].first >= 0){
				if (adj[input[j][i].first][n] > input[j][i].second || adj[input[j][i].first][n] == -1){
					adj[input[j][i].first][n] = input[j][i].second;
					adj[n][input[j][i].first] = input[j][i].second;
				}
			}
		}
	}
  bool a = false;
	int prim1 = mst(n);
	for (int i = 0; i < n; i++){
		if (vis[i] == false){
			a = true;
			break;
		}
	}
	int prim2 = mst(n + 1);
	if (a)
		cout << prim2;
	else
		cout << min(prim1, prim2);
}