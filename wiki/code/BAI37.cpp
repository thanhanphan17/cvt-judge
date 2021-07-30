#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
   int i,n,k,m,DoDai,Tang;
   freopen("BAI37.INP","r",stdin);
    freopen("BAI37.OUT","w+",stdout);
   cin>>k>>n;
   m=1;
   for(i=1;i<=k;i++)
    m=m*2; // -1 khi mà ô cần tìm vượt quá độ dài
   if(n>m) cout<<"-1"; else
   {
       Tang=1; DoDai=1;
       for(i=1;i<=k;i++)
       {
           m=m/2;
           if(n>m)
           {
               n=2*m-n+1;
               Tang=DoDai+(DoDai-Tang+1);
           }
           DoDai=DoDai*2;
       }
       cout<<Tang;
   }
}
