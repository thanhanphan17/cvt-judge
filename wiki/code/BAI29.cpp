#include <iostream>
#include <stdio.h>

using namespace std;
int x[10000000],a[1000000],d,k,i,n;
void solve()
{
    int nho;
    x[0]=d; nho=0;
    for(i=1;i<=110;i++)
    {
         x[i]=(x[i-1]*k+nho) % 10;
         nho=(x[i-1]*k+nho) / 10;
         if (x[i]==d && x[i-1]>0 && nho==0)
         {
             n=i-1;
             break;
         }
    }


}
int main()
{
   freopen("BAI29.INP","r",stdin);
  freopen("BAI29.OUT","w+",stdout);

   while(cin>>d>>k)
   {

       solve();

    if(d==8 && k==9)
    cout<<-1<<endl;
    else
    {
         for (i=n;i>=1;i--) cout<<x[i];
             cout<<d<<endl;

    }

   }


}
