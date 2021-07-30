#include <bits/stdc++.h>

using namespace std;
int n,m,l,g[10000],x,i;
string s,f[10000];
int main()
{
    freopen("XAUFIBO.inp","r",stdin);
    freopen("XAUFIBO.OUT","w",stdout);
    n=1;
    f[1]='b';
    f[2]='a';
    s="ba";
    x=2;
    g[1]=1;
    g[2]=1;
    while(n>0)
    {
        n=0;
        cin>>n>>m>>l;
        if(n>0)
        {
            l=l+m-1;
            while(x<n)
            {
                x=x+1;
                g[x]=g[x-1]+g[x-2];
                f[x]=f[x-1]+f[x-2];
            }
            if(m>g[n]) cout<<0<<" [0]"<<endl;
            if(m<g[n])
            {
                s=f[n];
                if(g[n]<l) l=g[n];
                cout<<l-m+1<<" [";
                for(i=m-1;i<=l-1;i++)
                    cout<<s[i];
                cout<<"]"<<endl;
            }
        }
    }
    return 0;
}
