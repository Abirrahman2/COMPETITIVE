#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>orderSet;
 // find_by_order, order_of_key, lower_bound, upper_bound, insert, erase
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        orderSet order_set;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            order_set.insert(x);
        }
        cout<<"Order set contained: "<<endl;
        for(auto it:order_set)
        {
            cout<<it<<" ";
        }
        cout<<endl;
        //in set, there is no concept of index.
        //find any element by giving index and it is possible here
        //i want to see what 0th index stored
        cout<<"0th index value: "<<*order_set.find_by_order(0)<<endl;
        cout<<"1st index value: "<<*order_set.find_by_order(1)<<endl;
        // now another functionality it provides which is order_of_key
        //if we want to see how many elements are less than the given value
        //we can use this function
        cout<<"how many elements are less than 4: "<<order_set.order_of_key(4)<<endl;


        //we can also found the upper bound and lower bound
        //upper bound means the first element that is greater than X.
        //lower bound means the first element that is greater than or equal to X.
        //order_set.upper_bound(X).
        cout<<"Upper bound of 5: "<<*order_set.upper_bound(5)<<endl;

        //lower bound
        cout<<"Lower bound of 5: "<<*order_set.lower_bound(5)<<endl;

        //we can also erase
        //if 3 is present in the order set ,3 will be removed
        //otherwise no effect.
        order_set.erase(3);
    }
}

