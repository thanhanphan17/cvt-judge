#include <bits/stdc++.h>
using namespace std;
int i,j,n,m,k;
int a[10000],h;
void rutgon(int &m,int &n)
{
    int a;
    if(n%m==0)
    {
        n=n/m;
        m=1;
    } else
    {
        int kt=0,g;
        if(m>=n) a=n;else a=m;
        while (kt==0)
        {
            a=a-1;
            if(m%a==0 && n%a==0) kt=1;
        }
        if(m%a>0 || n%a>0) a=1;
        n=n/a;
        m=m/a;
    }
}
int snn(int &m, int &n)
{
    int k=0;
    while(n>k*m)
    {
        k=k+1;
    }
    return k;
}
void trups(int &m, int &n,int a,int b)
{
    int gn;
    gn=n;
    m=m*b;
    n=n*b;
    a=a*gn;
    m=m-a;
    rutgon(m,n);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("BDTONG.INP","r",stdin);
    freopen("BDTONG.OUT","w",stdout);
    while(cin>>m)
    {
        cin>>n;
        rutgon(m,n);
        cout<<m<<" "<<n;
        k=snn(m,n);
        cout<<" "<<k;
        h=1;
        a[1]=k;
        while(m>1)
        {
            trups(m,n,1,k);
            if(m>1)
            {
                k=snn(m,n);
                h=h+1;
                a[h]=k;
            }else
            {
                h=h+1;
                a[h]=n;
            }
        }
        cout<<" "<<h<<" [";
        for(i=1;i<=h-1;i++)
            cout<<a[i]<<" ";
        cout<<a[h]<<"]"<<endl;
    }
    return 0;
}
