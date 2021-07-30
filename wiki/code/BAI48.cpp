#include <bits/stdc++.h>
using namespace std;
int dd[10001], x[10001];
   int xp, kt;
    int res;

int a, n, i, ck;
void Han()
{
freopen("BAI48.INP","r",stdin);
freopen("BAI48.OUT","w+",stdout);
  cin>>a>>n;
   dd[a]=1;
   x[1]=a;
   for (i=2 ;i<=10000;i++)
    {
         a=(a*a) % 10000;
         x[i]=a;
         if (dd[a]!=0)
            {
               xp=dd[a];
               kt=i;
               break;

            }
         dd[a]=i;
    }
   if (n<xp) res=x[n]; else
    {

         ck=kt-xp;
         n=xp+(n-xp) % ck;
         res=x[n];
    }
  cout<<res;

    }
int main()
{
Han();
}
