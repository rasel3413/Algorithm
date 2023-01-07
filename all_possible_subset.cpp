#include <bits/stdc++.h>
using namespace std;
#define fo(i,x) for(int i=0;i<x;i++)
#define vec vector<int>

void generate_all_subset(int n,vec &v)
{
   for(int mask=0;mask<(1<<n);mask++)
   {
      for(int j=0;j<n;j++)
      {
           if(mask&(1<<j))
           {
            cout<<v[j]<<" ";
           }
      }
      cout<<endl;

   }
}
int32_t main()
{
   int n;
   cin>>n;
   vec v(n);
   fo(i,n){
      cin>>v[i];
   }
   generate_all_subset(n,v);


}
