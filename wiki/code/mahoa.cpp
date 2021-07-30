#include <iostream>
#include <stdio.h>
using namespace std;

int TongChuSo(int x)
{
   int tong=0;
   int tam;
   while(x!=0)
   {
        tam=x%10;
        tong=tong+tam;
        x=x/10;
   }
   return tong;
}
int main()
{
    int n,i;
    int a[100000];
    freopen("MAHOA.INP","r",stdin);
    freopen("MAHOA.OUT","w+",stdout);
    cin>>n;
    for(i=1;i<=82;i++)
    {
        a[i]=n-i;
    }
         for(i=1;i<=82;i++)
        {
               if(n-a[i]==TongChuSo(a[i]))
               cout<<a[i]<<' ';
        }
}
