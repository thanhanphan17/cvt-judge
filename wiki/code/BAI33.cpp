#include <iostream>
#include <stdio.h>

using namespace std;
int n,t,i;
int main()
{
 freopen("BAI33.INP","r",stdin);
   freopen("BAI33.OUT","w+",stdout);
   cin>>n;
   t=1;
   for(i=1;i<=n-1;i++)
   t=t*2;
   t++;
   cout<<t*t;
}
