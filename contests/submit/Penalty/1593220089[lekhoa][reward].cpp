#include <bits/stdc++.h>

using namespace std;

int main()
{ int n,i,t=0,d=0;
 freopen("reward.inp","r",stdin);
 freopen("reward.out","w+",stdout);
  cin>>n;
  int a[n+1],f[n+1]={0};
   f[0]=0;
   for(i=1;i<=n;i++)
     cin>>a[i];
    if(a[1]>0)
      {f[1]=a[1];
        f[2]=a[1];}
     if(a[2]>0)
           f[2]+=a[2];
     for(i=3;i<=n;i++)
        f[i]=max(f[i-1],max(f[i-2]+a[i],f[i-3]+a[i-1]+a[i]));
     cout<<f[n];

}
