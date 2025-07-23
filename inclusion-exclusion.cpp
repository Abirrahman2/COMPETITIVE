#include<bits/stdc++.h>
using namespace std;

long long fun(long long n)
{
     int arr[4]={2,3,5,7};
    //so first we need to know about inclusion and exclusion property.
     //f(AUBUC)=f(A)+f(B)+f(C))-f(A intersection B)-f(A intersection C)-f(B intersection C)+f(A intersection B intersection C)
    //because we are trying to find out how many numbers are there which are divisible by 2,3,5,7
    //we just simply apply this above formula.
    //so here four numbers, we have 2^4 -1 combinations.
    long long ans=n;//first we assuming we have all the good numbers. then from this we will delete or add.
    for(int i=1;i<(1<<4);i++)//2^4 -1 combination.ignoring 0000.
    {
        int symbol=1;
        int multi=1;
        for(int j=0;j<4;j++)
        {
            if((i&(1<<j)))
            {
                multi=multi*arr[j];
                symbol=symbol*-1;//in the formula, in even position, we subtract and for odd we add.
                                 // but after finding the sum what we will do?
                                 // total -sum. right?
                                 //so here simply sign will be changed.
                                 //now in odd we have negative and even we have positive.
            }
        }
        ans=ans+(symbol*(n/multi));


    }
    return ans;

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
       long long l,r;
       cin>>l>>r;
       long long ans1=fun(r);
       long long ans2=fun(l-1);
       cout<<(ans1-ans2)<<endl;

    }
}

