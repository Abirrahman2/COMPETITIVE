#include<bits/stdc++.h>
using namespace std;
vector<string> duval(string s)
{
    int n=s.size();
    int i=0;
    vector<string>factor;
    while(i<n)
    {
        int j=i+1;
        int k=i;
        while(j<n && s[k]<=s[j])
        {
            if(s[k]==s[j])
            {
                k++;
            }
            else
            {
                k=i;
            }
            j++;
        }
        while(i<=k)
        {
            factor.push_back(s.substr(i,j-k));
            i=i+j-k;
        }

    }
    return factor;
}
int main()
{
    string s;
    cin>>s;
    vector<string>ans=duval(s);
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
}

