#include<bits/stdc++.h>
using namespace std;
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
   int i=n;
   int j=m;
   string ans="";
   while(i>0 && j>0)
   {
       if(s[i-1]==ss[j-1])
       {
        ans=s[i-1]+ans;
        i--;
        j--;
       }
       else{
          if(dp[i-1][j]>dp[i][j-1])
          {
              i--;
          }
          else{
            j--;
          }
       }
   }

   cout<<dp[n][m]<<endl;
   cout<<ans<<endl;
}
