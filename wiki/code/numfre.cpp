#include <bits/stdc++.h>

using namespace std;
int invert(int n)
{
   int y=0;
    while(n>0)
    {
        y=y*10+n%10;
        n=n/10;
    }
    return y;

}
int main()
{
    freopen("numfre.inp","r",stdin);
    freopen("numfre.out","w+",stdout);
    int n,d=0,i,a,b;
    cin>>a>>b;
    for(i=a;i<=b;i++)
    {
        if( __gcd(i,invert(i))==1) d++;
    }
    cout<<1;
}
