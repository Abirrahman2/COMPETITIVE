//first we need to understand fermat's little theorem
// we know how arithmatic mod work
//but for division we can not do directly mod operation
//example: (a/b) mod p != (a mod p)/(b mod p) mod p
//so this is incorrect.
//now we need to use fermats little theorem.
// a/b = a*b^-1
//so we can say a/b mod p= (a*b^-1)%mod
//a^p-1 mod p = 1 mod p ,here p is a prime and a is not divisible by a
//a^p mod p = a mod p (this is the fermats theorem)
//so now a^p-1 = 1 mod p
//a^p-1 *a^-1= 1* a^-1 mod p
// a^p-2=a^-1 mod p , this will help me to find mod for division
// a/b mod p = a*b^-1 mod p
//=> a/b mod p= a*b^p-2 mod p (so we convert negative power to positive integer)
//nCr, for large value we can find out easily
//nCr=(n! mod p * r!^p-2 mod p * (n-r)!^p-2 mod p ) mod p
//we need exponentiation function
//we need to find factorial efficiently
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//find power
//this will take log(b)
const ll p=1000000007;
const ll N=100001;
ll exp(ll a , ll b)
{

    if(b==0)
    {
        return 0;
    }
    if(b==1)
    {
        return a;
    }
    long long half=exp(a,b/2)%p;
    long long ans=(half*half)%p;
    if(b%2==1)
    {
        ans=(ans*a)%p;
    }
    return ans;
}
vector<ll>fac(N);
void factorials()
{
    fac[0]=1;
    fac[1]=1;
    for(int i=2;i<N;i++)
    {

        fac[i]=(fac[i-1]*i)%p;
    }
}
ll nCr(ll n,ll r)
{
    if(r>n) return 0;
   return (fac[n]%p * exp(fac[r],p-2)%p * exp(fac[n-r],p-2)%p)%p;
}
int main()
{
    factorials();
   // cout<<fac[4]<<endl;
   // cout<<exp(2,3);
   cout<<nCr(20,5);

}

