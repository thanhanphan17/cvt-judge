#include <bits/stdc++.h>

using namespace std;
int i,j,n,a,k,dau,kd,h,v;
long long  lon,tich;
string s;
int main()
{
    freopen("AROWMAX.inp","r",stdin);
    freopen("AROWMAX.out","w",stdout);
    cin>>n>>k;
    cin>>s;
    v=k-1;
    tich=1;
    i=0;
    h=0;
    kd=s[0]-48;
    for(i=0;i<=n-1;i++)
    {
        a=s[i]-48;
        if(a>0)
        {
            tich=tich*a;
            if(i>v)
            {
                v=v+1;
                tich=tich/kd;
                h=h+1;
                kd=s[h]-48;
            }
            if(lon<tich) lon=tich;
        }
        if(a==0)
        {
            tich=1;
            h=i+1;
            kd=s[h]-48;
            v=i+k;
        }
    }
    cout<<lon;
    return 0;
}
