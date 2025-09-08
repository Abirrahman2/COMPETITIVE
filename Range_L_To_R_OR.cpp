#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll checkBit(ll left,ll i)
{
    return (left>>i)& 1;
}
ll findOR(ll l,ll r)
{
    ll ans=0;
    ll track=-1;
  for(ll i=60;i>=0;i--)
  {
      if(checkBit(l,i)!=checkBit(r,i))
      {
          track=i;
          break;
      }
      else{
        ans=ans+(checkBit(l,i)<<i);
      }

  }
   if(track!=-1)
   {
       track++;
       ans=ans+((1LL<<track))-1;
   }
  return ans;
}
int main()
{
  ll l,r;
  cin>>l>>r;
  cout<<findOR(l,r)<<endl;
}


