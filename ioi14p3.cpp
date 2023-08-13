#include <bits/stdc++.h>
#include "game.h"

using namespace std;

const int MM = 1501;
static int ne[MM][MM];
int p[MM], n;

void initialize(int m){
	n=m;
	for(int i = 1; i <= n; i++){
		p[i]=i;
		for(int j = 1; j <= n; j++)if(i!=j)ne[i][j]=1;
	}
}

void join(int a, int b)
{
	for(int i = 1; i <= n; i++)if(p[i] == b)p[i] = a;
    for(int i = 1; i <= n; i++){
		int t1 = ne[a][i], t2 = ne[b][i];
		ne[a][i] = ne[i][a] = t1+t2;
	}
}

int hasEdge(int u, int v){
	u++;
	v++;
	int p1=p[u], p2=p[v];
	if(ne[p1][p2] > 1){
		ne[p1][p2]--; ne[p2][p1]--;
		return 0;
	}

	ne[p1][p2]=ne[p2][p1]=0;
	join(p1, p2);
	return 1;
}