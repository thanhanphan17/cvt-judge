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
        if (a[i]>0)
        {
            if (i==1)  f[i]=a[i];
            else if (i==2)  f[i]=a[i]+a[i-1];
            else  f[i]=max(f[i-1],max(f[i-2]+a[i],f[i-3]+a[i]+a[i-1]));
            ++d;
        }
    }
    if (d==0)  cout<<d;
    else  cout<<f[n];
    return 0;
}
