#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int m;
        cin>>m;
        vector<pair<int,int>>adj[n];
        for(int i=0;i<m;i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});

        }
       /* for(int i=0;i<n;i++)
        {
            for(auto it:adj[i])
            {
                cout<<it<<" ";
            }
            cout<<endl;
        }*/
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
                        greater<pair<int,pair<int,int>>>>pq;
        vector<int>vis(n,0);
        pq.push({0,{0,-1}});
        int sum=0;
        while(!pq.empty())
        {
            pair<int,pair<int,int>>p=pq.top();
            pq.pop();
            int node=p.second.first;
            int w=p.first;
            if(vis[node]==1)
            {
                continue;
            }
            vis[node]=1;
            sum=sum+w;
            for(auto it:adj[node])
            {
                int adjNode=it.first;
                if(vis[adjNode]==0)
                {
                 pq.push({it.second,{adjNode,node}});
                }

            }
        }

        cout<<sum<<endl;



    }
}


