#include<bits/stdc++.h>
using namespace std;
void topodfs(int node,vector<int>adj[],int vis[],stack<int>&st)
{
    vis[node]=1;
    for(auto it:adj[node])
    {
        if(vis[it]==0)
        {
            topodfs(it,adj,vis,st);
        }
    }
    st.push(node);
}
int main()
{
    int t;
    cin>>t;
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
            //Topological sort only work for DAG
        }
        int vis[n]={0};
        vector<int>ans;
        stack<int>st;
        for(int i=0;i<n;i++) // considering starting node is 0.
        {
            if(vis[i]==0)
            {
                topodfs(i,adj,vis,st);
            }

        }

        while(!st.empty())
        {
            int node=st.top();
            st.pop();
            ans.push_back(node);
        }
        for(auto it:ans)
        {
            cout<<it<<" ";
        }
        cout<<endl;
    }
}

