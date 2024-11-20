#include<bits/stdc++.h>
using namespace std;
bool detect(int node,vector<int>adj[],int vis[],int path[])
{
    vis[node]=1;
    path[node]=1;


    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            if(detect(it,adj,vis,path)==true)
            {
                return true;
            }
        }
        else if(path[it])
        {
            return true;
        }
    }




    path[node]=0;
    return false;
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
        int vis[n]={0};
        int path[n]={0};
        for(int i=0;i<m;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
        }

        bool a=false;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                if(detect(i,adj,vis,path))
                {
                    cout<<"DETECTED"<<endl;
                    a=true;
                    break;
                }
            }
        }
        if(a==false)
        {
            cout<<"NOT DETECTED"<<endl;
        }
    }
}

