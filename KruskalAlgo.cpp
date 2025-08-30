#include<bits/stdc++.h>
using namespace std;
class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>adj[n];
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});//this is not required
    }
    vector<pair<int,pair<int,int>>>edges;
    for(int i=0;i<n;i++)
    {
        for(auto it:adj[i])
        {
            int u=i;
            int v=it.first;
            int w=it.second;
            edges.push_back({w,{u,v}});
        }
    }
    sort(edges.begin(),edges.end());
    DisjointSet dsu(n);
    int sum=0;
    for(auto it:edges)
    {
        int w=it.first;
        int u=it.second.first;
        int v=it.second.second;
        if(dsu.findUPar(u)!=dsu.findUPar(v))
        {
            sum=sum+w;
            dsu.unionByRank(u,v);
        }
    }
    cout<<sum<<endl;

}
