class Solution {
public:
   vector<int>createNewArray(int i,int j,int k,int n,vector<int>&v)
   {
    vector<int>sub;
    for(int m=i;m<=j;m++)
    {
        sub.push_back(v[m]);
    }
    vector<int>rem;
    for(int m=0;m<i;m++)
    {
        rem.push_back(v[m]);
    }
    for(int m=j+1;m<n;m++)
    {
        rem.push_back(v[m]);
    }
    vector<int>vv;
    for(int m=0;m<k;m++)
    {
        vv.push_back(rem[m]);
    }
    for(int m=0;m<sub.size();m++)
    {
        vv.push_back(sub[m]);
    }
    for(int m=k;m<rem.size();m++)
    {
        vv.push_back(rem[m]);
    }

    return vv;
   }
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        queue<pair<int,vector<int>>>q;
        q.push({0,nums1});
        set<vector<int>>st;
        while(!q.empty())
        {
            pair<int,vector<int>>pp=q.front();
            int step=pp.first;
            vector<int>v=pp.second;
            if(v==nums2)return step;
            q.pop();
            for(int i=0;i<n;i++)
            {
                for(int j=i;j<n;j++)
                {
                    int si=n-(j-i+1);

                    for(int k=0;k<=si;k++)
                    {
                        vector<int>vv=createNewArray(i,j,k,n,v);

                        if(vv==nums2)
                        {
                           return step+1;
                        }
                        else
                        {

                            if(st.find(vv)==st.end())
                            {
                                q.push({step+1,vv});
                                st.insert(vv);
                            }

                        }

                    }
                }
            }
        }
        return n-1;
    }
};
