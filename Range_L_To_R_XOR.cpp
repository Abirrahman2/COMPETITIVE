#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll findVal(ll n)
{
    if(n%4==0) return n;
    if(n%4==1) return 1;
    if(n%4==2) return n+1;
    if(n%4==3) return 0;
}
ll findXOR(ll l, ll r)
{
    return (findVal(l-1) ^ findVal(r));
}
int main()
{

  ll l,r;
  cin>>l>>r;
  cout<<findXOR(l,r)<<endl;
}

