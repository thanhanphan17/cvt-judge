#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n,i,j;
    int a[1000];
    freopen("BAI09.INP","r",stdin);
    freopen("BAI09.OUT","w+",stdout);
    cin>>n;
    for(i=1;i<=n;i++)
    cin>>a[i];

   int dem=0;
   for (i=1;i<=n;i++)
  {
   for(j=1;j<=i;j++)
  {
   if (a[j]>a[i])
   dem++;
  }

   cout<<dem<<' ';
   dem=0;
  }

    return 0;
}
