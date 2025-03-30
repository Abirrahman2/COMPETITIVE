#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    //cin>>t;
    t=1;
    while(t--)
    {
        long long n,m;
        cin>>n>>m;
        vector<pair<long long,long long>>adj[n+1];
        for(long long i=0;i<m;i++)
        {
            long long u,v,w;
            cin>>u>>v>>w;
            adj[u].push_back({v,w});
        }
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq;
        pq.push({0,1});
        long long dis[n+1];
        for(long long i=0;i<n+1;i++)
        {
            dis[i]=LLONG_MAX;
        }
        dis[1]=0;
        while(!pq.empty())
        {
            long long distance=pq.top().first;
            long long node=pq.top().second;
            pq.pop();
            if(distance>dis[node])
            {
                continue;
            }
            for(auto it:adj[node])
            {
                long long child=it.first;
                long long weight=it.second;
                long long sum=distance+weight;
                if(sum<dis[child])
                {
                    dis[child]=sum;
                    pq.push({sum,child});
                }
            }
        }
        for(long long i=1;i<=n;i++)
        {
            cout<<dis[i]<<" ";
        }
        cout<<endl;


    }
}

