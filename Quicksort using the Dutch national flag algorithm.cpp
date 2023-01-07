#include <bits/stdc++.h>
using namespace std;
pair<int,int>part(int lo,int hi,vector<int>&arr)
{
    int pivot=arr[hi];
    int mid=lo;
    while(mid<=hi)
    {
        if(arr[mid]<pivot){
            swap(arr[mid],arr[lo]);
            lo++;
            mid++;
        }
        else if(arr[mid]>pivot){
            swap(arr[mid],arr[hi]);
            hi--;
        }
        else{
            mid++;
        }
    }
    return make_pair(lo-1,mid);
}
void quicksort(int lo,int hi,vector<int>&arr)
{
    if(lo>=hi)return;
    if(hi-lo==1){
        if(arr[lo]>arr[hi]){
            swap(arr[lo],arr[hi]);
        }
        return;
    }
    pair<int,int>pi=part(lo,hi,arr);
    quicksort(lo,pi.first,arr);
    quicksort(pi.second,hi,arr);
}
vector<int> quickSortUsingDutchNationalFlag(vector<int> &arr)
{
    // Write your code here.
    int lo=0,hi=arr.size()-1;
    quicksort(lo,hi,arr);
    return arr;
}
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;i++)cin>>v[i];
      vector<int>ans=  quickSortUsingDutchNationalFlag(v);
      for(int i=0;i<n;i++)
      {
          cout<<ans[i]<<" ";
      }
      cout<<endl;

    }
}
