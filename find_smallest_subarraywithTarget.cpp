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
        string s;
        cin>>s;
        //this technique is very useful in many sub-array related problems.

        //here we need to find the substring,which we should remove to make a,b equal in this string.


        //here target means the difference of occurrence a and b.
        //first we will find difference array with respect to 0th index.
        int target=0;
        int cnta=0;
        int cntb=0;
        for(int i=0;i<n;i++)
        {
        if(s[i]=='a')
        {
            cnta++;
        }
        else{
            cntb++;
        }

        }
        target=cnta-cntb;//negative is ok. because in difference array we will get negative value if target is negative.
        //that means occurrence of a is smaller than occurrence of b.
        int dif[n+1]={0};
        if(target==0)
        {
            cout<<0<<endl;
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            if(s[i-1]=='a')
            {
                dif[i]=dif[i-1]+1;
            }
            else{
                dif[i]=dif[i-1]-1;
            }
        }
//        for(int i=0;i<n;i++)
//        {
//            cout<<dif[i]<<" ";
//        }
//        cout<<endl;
        map<int,int>mp;//this will store difference, index pair.
        mp[0]=0;//this should be done.
        //because we might get difference equal target from starting index.
        int ans=n+1;
        for(int i=1;i<=n;i++)
        {
            int difference=dif[i]-target;
            if(mp.find(difference)!=mp.end())
            {
                ans=min(i-mp[difference],ans);
            }
            mp[dif[i]]=i;
        }
        if(ans>=n)
        {
            cout<<-1<<endl;
        }
        else{
            cout<<ans<<endl;
        }

    }
}

