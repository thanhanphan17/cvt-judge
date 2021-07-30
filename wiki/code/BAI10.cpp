#include <algorithm>
#include <iostream>
#include <windows.h>
#include <stdio.h>
using namespace std;
int kiemtra(int m,int h,int b[])
{
    int i,j;
    j=0;
    sort(b+1,b+1+h);
    for(i=h;i>=1;i--)
        if (b[i]>=m) m--;
    return m;
}
int main()
{
    freopen("BAI10.INP","r",stdin);freopen("BAI10.OUT","w",stdout);
    int n,a[100],b[100],c[100],i,j,k,h,m;
    cin>>n;
    for (i=1;i<=n;i++)
        cin>>a[i];
    h=0;
    for (i=n;i>=1;i--)
    {
        m=n-a[i];
        m=kiemtra(m,h,b);
        h++;
        b[h]=m;
        c[h]=m;
    }
    for (i=h;i>=1;i--)
        cout<<c[i]<<" ";
    return 0;
}
