#include<bits/stdc++.h>
using namespace std;
void mergeS(int arr[],int low,int mid,int high)
{
    int l=low;
    int r=mid+1;
    vector<int>temp;
    while(l<=mid && r<=high)
    {
        if(arr[l]>arr[r])
        {
            //swap(arr[l],arr[r]);
             temp.push_back(arr[r]);
             r++;
        }
        else{
            temp.push_back(arr[l]);
            l++;
        }
    }
    while(l<=mid)
    {
        temp.push_back(arr[l]);
        l++;
    }
    while(r<=high)
    {
        temp.push_back(arr[r]);
        r++;
    }
    for(int i=low;i<=high;i++)
    {
        arr[i]=temp[i-low];
    }

}
void mergeSort(int arr[],int low,int high)
{

   if(low>=high)return;
   int mid=(low+high)/2;
   mergeSort(arr,low,mid);
   mergeSort(arr,mid+1,high);
   mergeS(arr,low,mid,high);
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

}

