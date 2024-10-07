#include<bits/stdc++.h>
using namespace std;
long long power(int base,int n)
{
    long long val=1;
    while(n!=0)
    {
        if(n%2==0)
        {
            base=base*base;
            n=n/2;
        }
        else{
            val=val*base;
            n--;
        }
    }
    return val;
}
int main()
{
   int base,n;
   cin>>base>>n;
   cout<<power(base,n)<<endl;
}

