#include<bits/stdc++.h>
using namespace std;
int MCM(int i,int j,int arr[],vector<vector<int>>&dp)
{
    if(i==j)
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int mini=INT_MAX;
    for(int k=i;k<j;k++)
    {
        int firstPartition=0;
        int secondPartition=0;
        if(dp[i][k]!=-1)
        {
            firstPartition=dp[i][k];
        }
        else{
            firstPartition=MCM(i,k,arr,dp);
        }
        if(dp[k+1][j]!=-1)
        {
            secondPartition=dp[k+1][j];
        }
        else{
            secondPartition=MCM(k+1,j,arr,dp);
        }
       int steps=(arr[i-1]*arr[j]*arr[k])+firstPartition+secondPartition;
        mini=min(steps,mini);
    }
    return dp[i][j]=mini;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    vector<vector<int>>dp(n,vector<int>(n,-1));
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<MCM(1,n-1,arr,dp)<<endl;
}

