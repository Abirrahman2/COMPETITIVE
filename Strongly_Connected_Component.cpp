#include<bits/stdc++.h>
using namespace std;
void topoSort(int node,int vis[],vector<int>adj[],stack<int>&st)
{
    vis[node]=1;
    for(auto it:adj[node])
    {
        if(vis[it]==0)
        {
            topoSort(it,vis,adj,st);
        }
    }
    st.push(node);
}
void dfs(int node,int vis[],vector<int>adj[])
{
    vis[node]=1;
    for(auto it:adj[node])
    {
        if(vis[it]==0)
        {
            dfs(it,vis,adj);
        }
    }
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
        for(int i=0;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
        }
        stack<int>st;
        int vis[n]={0};
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                topoSort(i,vis,adj,st);
            }
        }
        vector<int>adjT[n];
        for(int i=0;i<n;i++)
        {
            for(auto it:adj[i])
            {
                adjT[it].push_back(i);
            }
        }
        int ssc=0;
        int visT[n]={0};
        while(!st.empty())
        {
            int node=st.top();
            st.pop();
            if(visT[node]==0)
            {
                ssc++;
                dfs(node,visT,adjT);
            }
        }

        cout<<ssc<<endl;
    }
}

