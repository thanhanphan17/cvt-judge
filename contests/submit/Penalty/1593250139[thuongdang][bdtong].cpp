#include <bits/stdc++.h>

using namespace std;

int ucln (int a,int b)
{
    if (a*b)
    {
        while (a!=b)
        if (a>b)  a-=b;
        else  b-=a;
        return a;
    }
    else  return 1;
}

int bcnn (int a,int b)
{
    int lcm=a*b;
    a=ucln(a,b);
    return lcm/a;
}

int main()
{
    freopen("bdtong.inp","r",stdin);
    freopen("bdtong.out","w+",stdout);
    int k,i,f[10010],d,n,m;
    while (cin>>m>>n)
    {
        k=ucln(m,n);
        m/=k;
        n/=k;
        cout<<m<<" "<<n<<" ";
        d=0;
        while (m>0)
        {
            i=1;
            while (n>m*i)  ++i;
            m=m*i-n;
            n=n*i;
            ++d;
            f[d]=i;
            k=ucln(m,n);
            m/=k;
            n/=k;
        }
        cout<<f[1]<<" ";
        cout<<d<<" "<<"[";
        for (i=1;i<=d;++i)
            if (i<d)  cout<<f[i]<<" ";
            else  cout<<f[i]<<"]"<<endl;
    }
    return 0;
}
