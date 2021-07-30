#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k,a[2010],i,j,t,kq=1;
    string s;
    freopen("arowmax.inp","r",stdin);
    freopen("arowmax.out","w+",stdout);
    cin>>n>>k;
    cin>>s;
    for (i=0;i<n;++i)  a[i+1]=s[i]-48;
    for (i=1;i<=n-k+1;++i)
        if (a[i]!=0)
        {
            t=1;
            for (j=i;j<=i+k-1;++j)
            {
                t*=a[j];
                if (t==0)  break;
            }
            kq=max(kq,t);
        }
    cout<<kq;
    return 0;
}
