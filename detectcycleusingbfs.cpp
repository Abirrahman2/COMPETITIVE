#include<bits/stdc++.h>
using namespace std;
//remember, this code is only for a single connected component.
//if graph contains multiple component , then we should run this algorithm for every node.
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<pair<int,int>>q;
    q.push({1,-1});
    vector<int>vis(n+1,0);
    vis[1]=1;
    bool cycle=false;
    while(!q.empty())
    {
      int node=q.front().first;
      int parent=q.front().second;
      q.pop();
      for(auto it:adj[node])
      {
          if(vis[it]==1 && parent!=it)
          {
              cycle=true;
              break;
          }
          else if(vis[it]==0){
            vis[it]=1;
            q.push({it,node});
          }
      }
      if(cycle)
      {
          break;
      }
    }
    if(cycle)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
}
