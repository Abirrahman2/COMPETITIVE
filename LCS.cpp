#include<bits/stdc++.h>
using namespace std;
int lcs(int ind1,int ind2,string &s,string &ss, vector<vector<int>>&dp)
{
    if(ind1<0 || ind2<0)return 0;
    if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
    if(s[ind1]==ss[ind2])
    {
        return dp[ind1][ind2]=1+lcs(ind1-1,ind2-1,s,ss,dp);

    }
    else
    {

        return dp[ind1][ind2]=0+max(lcs(ind1,ind2-1,s,ss,dp),lcs(ind1-1,ind2,s,ss,dp));
    }
}
int main()
{
   string s,ss;
   cin>>s>>ss;
   int n=s.size();
   int m=ss.size();
   //vector<vector<int>>dp(n,vector<int>(m,-1));
   //int longestLength=lcs(s.size()-1,ss.size()-1,s,ss,dp);
   //tabulation
   vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
   for(int i=0;i<=n;i++)
   {
       dp[i][0]=0;
   }
   for(int i=0;i<=m;i++)
   {
       dp[0][i]=0;
   }
   for(int i=1;i<=n;i++)
   {
       for(int j=1;j<=m;j++)
       {
           if(s[i-1]==ss[j-1])
           {
               dp[i][j]=1+dp[i-1][j-1];
           }
           else
           {

               dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
           }

       }
   }
   cout<<dp[n][m]<<endl;
}

