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
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        vector<vector<int>>all;
        int subsets=1<<n;
        for(int i=0;i<subsets;i++)
        {
            vector<int>subset;
            for(int j=0;j<n;j++)
            {
                if((i & (1<<j)))
                {
                    subset.push_back(arr[j]);
                }
            }
            all.push_back(subset);
        }
        for(int i=0;i<all.size();i++)
        {
            for(int j=0;j<all[i].size();j++)
            {
                cout<<all[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}

