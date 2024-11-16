#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<int>adj[n];
        int indegree[n]={0};
        for(int i=0;i<m;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            indegree[v]++;
            //Topological sort only work for DAG
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        //now i will store all the toposort.
        vector<int>ans;
        while(!q.empty())
        {

            int node=q.front();
            q.pop();
            for(auto it:adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    q.push(it);
                }
            }
            ans.push_back(node);
        }
        for(auto it:ans)
        {
            cout<<it<<" ";
        }
        cout<<endl;
    }
}
