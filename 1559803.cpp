#include <bits/stdc++.h>
using namespace std;
#define MM 500001
vector<int> G[MM];
long n, tot[MM], ans= LONG_MIN;
int dfs(int x){
  for(int i=0;i<(int)G[x].size();i++){
    int v=G[x][i];
    tot[x] += dfs(v);
  }
  return tot[x];
}
int main(){
  cin>>n;
  for(int i=0;i<n-1;i++){
    int a, b;
    cin>>a>>b;
    G[a].push_back(b);
  }
  for(int i=1;i<=n;i++)
    cin>>tot[i];
  dfs(1);
  for(int i=1;i<=n;i++)
    if(tot[i]>ans)
      ans=tot[i];
  cout<<ans<<endl;
}