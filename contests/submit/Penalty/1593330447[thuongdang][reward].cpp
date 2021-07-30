#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("reward.inp","r",stdin);
    freopen("reward.out","w+",stdout);
    int n;
    cin>>n;
    int a[n+10],i,d=0,t=0,f[n+10],max1;
    f[0]=0;
    for (i=1;i<=n;++i)
    {
        cin>>a[i];
        if (i==1)  max1=f[i]=a[i];
        else
        {
            max1=max(max1,a[i]);
            if (i==2)  f[i]=max(a[i]+a[i-1],max(a[i],a[i-1]));
            else  f[i]=max(f[i-1],max(f[i-2]+a[i],f[i-3]+a[i]+a[i-1]));
        }
    }
    if (max1>f[n])  cout<<max1;
    else  cout<<f[n];
    return 0;
}
