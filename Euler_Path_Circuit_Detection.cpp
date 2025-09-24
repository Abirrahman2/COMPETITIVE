#include<bits/stdc++.h>
using namespace std;
void dfs(int i,vector<int>&vis,vector<int>adj[])
{
    vis[i]=1;

    for(auto it:adj[i])
    {
        if(vis[it]==0)
        {
            dfs(it,vis,adj);
        }
    }
}
int isEulerCircuit(int V, vector<int> adj[]) {
    vector<int>degree(V,0);
    for(int i=0;i<V;i++)
    {
        for(auto it:adj[i])
        {
            degree[it]++;
        }
    }
    bool checkCircuit=false;
    bool checkPath=false;

    //first i will check is all non-zero degree nodes are in single component or not.
    vector<int>vis(V,0);
    dfs(1,vis,adj);
    for(int i=0;i<V;i++)
    {
        if(vis[i]==0 && degree[i]!=0)
        {
            return 0;
        }
    }
    vector<int>v;
    for(int i=0;i<V;i++)
    {
        if(degree[i]%2==1)
        {
            v.push_back(i);
        }
    }
    if(v.size()==2)
    {
        return 1;
    }
    if(v.size()==0)
    {
        return 2;
    }
    return 0;


}
int main()
{
    int t;
    //cin>>t;
    t=1;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<int>adj[n];
        for(int i=0;i<m;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cout<<isEulerCircuit(n,adj)<<endl;
    }
}




