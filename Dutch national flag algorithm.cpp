#include <bits/stdc++.h>
using namespace std;
void sort012(int *arr, int n)
{
   //   Write your code here
    int low=0,mid=0,hi=n-1;
    while(mid<=hi)
    {
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[mid],arr[hi]);
            hi--;

        }
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    cout<<"Only input 0 , 1 and 2"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort012(arr,n);
     for(int i=0;i<n;i++)
    {
       cout<<arr[i]<<" ";
    }
    cout<<endl;
}
