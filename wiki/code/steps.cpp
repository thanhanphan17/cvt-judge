#include <bits/stdc++.h>

using namespace std;
long long n,k,i;
long long dd[100000],f[100000],ds;
void init()
{
    int i,u;
    cin>>n>>k;
    for(i=1;i<=k;i++)
    {
        dd[i]=0;
    }
     for (i=1;i<=k;i++)
     {
          cin>>u;
          dd[u]=1;
     }
}
void caculate()
{
   f[1]=1; f[0]=1;
   for(i=2;i<=n;i++)
      if (dd[i]==1) f[i]=0; else
      {
         f[i]=(f[i-1]+f[i-2]) % 26051968;
      }
   ds=f[n];
}
int main()
{
    //freopen("steps.inp","r",stdin);
        //freopen("steps.out","w+",stdout);
    init();
    caculate();
    cout<<ds;
}
