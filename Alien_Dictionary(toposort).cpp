#include<bits/stdc++.h>
using namespace std;
 string findOrder(vector<string> &words) {
        // code here
        vector<int>adj[26];
        int track[26]={0};
        set<int>st;
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<words[i].size();j++)
            {
                track[words[i][j]-'a']=1;
                st.insert(words[i][j]-'a');

            }
        }

        for(int i=0;i<words.size()-1;i++)
        {
            string s1=words[i];
            string s2=words[i+1];
            int len=min(s1.size(),s2.size());
            int maxiLen=max(s1.size(),s2.size());

            bool track2=false;
            for(int j=0;j<len;j++)
            {

                if(s1[j]!=s2[j])
                {
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    track2=true;
                    break;
                }

            }
            if(track2==false)
            {
                if(s1.size()>s2.size())
                {
                    return "";
                }
            }

        }
        int indegree[26]={0};
        int count=0;
        for(int i=0;i<26;i++)
        {
            if(track[i]==1)
            {
            for(auto it:adj[i])
            {

               indegree[it]++;

            }

            }

        }
        queue<int>q;
        for(int i=0;i<26;i++)
        {
            if(indegree[i]==0 && track[i]==1)
            {
                q.push(i);
            }
        }
        vector<int>topo;
        while(!q.empty())
        {
            int node=q.front();
            topo.push_back(node);
            q.pop();
            for(auto it:adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    q.push(it);
                }
            }
        }
        if(st.size()!=topo.size())
        {
            return "";
        }
        string ans="";
        for(auto it:topo)
        {
            ans=ans+ (char)(it+'a');
        }
        return ans;

    }
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string>v;
        for(int i=0;i<n;i++)
        {

            string s;
            cin>>s;
            v.push_back(s);
        }
        cout<<findOrder(v)<<endl;

    }
}


