#include <bits/stdc++.h>

#define MM 5005

using namespace std;

vector <int> buff, adj[MM], g[MM];
int disc[MM], low[MM], N, M, Q, cnt, nSCC = 0, id[MM], gSize[MM];
bool st[MM];

void scc(int cur)
{
    disc[cur] = low[cur] = ++cnt;
    buff.push_back(cur); // push onto SCC stack
    st[cur] = true;
    for (int i = 0; i < adj[cur].size(); i++)
    {
        int v = adj[cur][i];
        if (disc[v] == 0)
            scc(v);
        if (st[v]) // condition for update
            low[cur] = min(low[cur], low[v]);
    }
    if (disc[cur] == low[cur]) // if cur is the start of a SCC
    {
        while (1)
        {
            int v = buff.back(); buff.pop_back(); st[v] = false;
            // do sth here
            id[v] = nSCC;
            gSize[nSCC]++;
            if (v == cur) break;
        }
        nSCC++;
    }
}
void process()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j : adj[i])
        {
            if (id[i]!=id[j])
            {
                g[id[i]].push_back(id[j]);
            }
        }
    }
    for (int i = 0; i < nSCC; i++)
        g[i].erase(unique(g[i].begin(), g[i].end()), g[i].end());
}
int dist[MM][MM];
bool done[MM];
void spfa(int src)
{
    for (int i = 0; i < nSCC; i++)
    {
        done[i] = false;
        dist[src][i] = -1;
    }
    queue <int> q;
    dist[src][src] = 0;
    q.push(src);
    done[src]=true;
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        done[cur] = false;
        for (int i : g[cur])
        {
            if (dist[src][cur] + gSize[i] > dist[src][i])
            {
                dist[src][i] = dist[src][cur] + gSize[i];
                if (!done[i])
                {
                    done[i] = true;
                    q.push(i);
                }
            }
        }
    }
}
void allpairlongest()
{
    for (int i = 0; i < nSCC; i++)
        spfa(i);
}
int main()
{
    scanf("%d%d%d", &N, &M, &Q);
    for (int i = 0,a ,b; i < M; i++)
    {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
    }
    for (int i = 1; i <= N; i++)
    {
        if (disc[i]==0)
            scc(i);
    }
    process();
    allpairlongest();
    for (int i = 0, a, b; i < Q; i++)
    {
        scanf("%d%d", &a, &b); bool t = true;
        if (id[a]==id[b]) t = false;
        if (!t)
        {
            printf("Indeterminate\n"); continue;
        }
        int ga= id[a], gb = id[b];
        int ans = -1;
        if (~dist[ga][gb])
        {
            ans = dist[ga][gb] - gSize[gb];
        }
        else if (~dist[gb][ga])
        {
            ans = dist[gb][ga] - gSize[ga];
            swap(a,b);
        }
        else
        {
            printf("Indeterminate\n"); continue;
        }
        printf("%d %d\n", a, ans);
    }
}