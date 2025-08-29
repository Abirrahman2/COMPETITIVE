#include<bits/stdc++.h>
using namespace std;
int timer=1;
//so this timer will tell the require steps to reach a particular node
void dfs(int node,int parent,int vis[],vector<int>adj[],int arrival[],int low[],vector<vector<int>>&ans)
{
    vis[node]=1;
    arrival[node]=timer;
    low[node]=timer;
        //so this algorithm have several cases that we need to consider
        //first case is if the node is not visited then go to it's adjacent node.
        //another case is ,because the graph is undirected, so we may encounter the node which basically the parent, so we will ignore this
        //and under first case, we need to modify our low array,
        //so the current node will ask to his neighbor, if we remove our edge, is it possible we will become disconnected?
        //and this is the heart of this problem.
        //so how this work?
        //first we will see that my current node's neighbor has low[it](this it is neighbor) value which lower then or equal to my current node's(which is node) arrival[node].
        //what it signify? it basically say , there is a path which can take my neighbor node to my current node. basically we have another path.
        //so if we remove my current node's edge with my neighbor node, i will not disconnected or neighbor node will not disconnected.
        //when i will disconnected from my neighbor node?
        //so whenever the my current node's arrival time is lower then the low value of my neighbor node, i will disconnected,
        //because there will be no path which my neighbor can take and reach my current node.
    for(auto it:adj[node])
    {
        if(it==parent)
        {
            continue;
        }
        if(vis[it]==0)
        {
           timer++;
           dfs(it,node,vis,adj,arrival,low,ans);
           //so after finishing the traversal,
           //my neighbor node contain the updated value of low array.
           low[node]=min(low[it],low[node]);
           //now check
          // if(low[it]<=arrival[node])
          // {
              // nothing will happen
              //that is why this can be ignored

           //}
           if(low[it]>arrival[node])
           {
               //this is the edge which is the bridge.
               ans.push_back({node,it});
           }

        }
        else{
            low[node]=min(low[it],low[node]);
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
        for(int i=0;i<m;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);

        }
        int arrival[n];
        int low[n];
        int vis[n]={0};
        vector<vector<int>>ans;//ans will store which edge is the bridge which can make a graph two or more component
        dfs(0,-1,vis,adj,arrival,low,ans);//assume we have only one component.
        for(auto it:ans)
        {
            cout<<it[0]<<" "<<it[1]<<endl;;
        }

    }
}

