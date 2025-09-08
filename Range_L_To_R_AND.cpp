#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool checkBit(ll left,ll i)
{
    return (left>>i)& 1;
}
ll findAND(ll l,ll r)
{
    ll ans=0;
  for(ll i=60;i>=0;i--)
  {
      if(checkBit(l,i)!=checkBit(r,i))
      {
          break;
      }
      else{
        ans=ans+(checkBit(l,i)<<i);
      }
  }
  return ans;
}
int main()
{
  ll l,r;
  cin>>l>>r;
  cout<<findAND(l,r)<<endl;
}

