#include <bits/stdc++.h>

using namespace std;

int main ()
{
    int mi,ma,n,i,j,t=0;
    int a[10000],s[10000];

   freopen ("BAI01.INP", "r", stdin);
   freopen ("BAI01.OUT", "w +", stdout);
   cin>>n;
   for(i=1;i<=n;i++)
   {
       cin>>a[i];
   }
    sort(a+1,a+n+1);
    cout <<fixed;
    cout <<setprecision(3) <<1.0*a[1]<<' '<<1.0*a[n]; }
