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
        map<string,pair<int,int>>mp;
        int val=-1;
        vector<pair<pair<string,string>,int>>v;
        for(int i=0;i<m;i++)
        {
            string s;
            string ss;
            int w;
            cin>>s>>ss>>w;
            int u,v;
            if(mp[s].first!=1)
            {
                val++;
                mp[s].second=val;
                mp[s].first=1;
                u=mp[s].second;
            }
            if(mp[ss].first!=1)
            {
                val++;
                mp[ss].first=1;
                mp[ss].second=val;
                v=mp[ss].second;

            }
            if(mp[s].first==1)
            {
                u=mp[s].second;
            }
            if(mp[ss].first==1)
            {
                v=mp[ss].second;
            }
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

