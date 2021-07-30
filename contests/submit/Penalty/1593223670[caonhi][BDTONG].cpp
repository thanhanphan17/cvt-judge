#include <bits/stdc++.h>

using namespace std;

int GDC(int& n, int& m)
{
    int k=1,i,a=n,b=m;
    if(a<b) swap(a,b);
    for(i=1; i<=b/2; i++)
    if((a%i==0)and(b%i==0)) k=i;
    return k;
}
int main()
{
    freopen("BDTONG.inp","r",stdin);
    freopen("BDTONG.out","w",stdout);
  int n,m;
  while(cin>>n>>m)
  {
  // cau a
  int ts=n/GDC(n,m),ms=m/GDC(n,m);
  cout<<ts<<" "<<ms<<" ";
  //cau b
  int k=m/n; if(m%n>0) k++;
  cout<<k<<" ";
  //cau c
  k=0; //int=h=ts/ms;
  int d=0,a[5000];
 // cout<<endl;
  while(ts>0)
  {
    k=ms/ts; if(ms%ts>0) k++;
    int tt=k*ts-ms,gg=ms*k;
    ts=tt/GDC(tt,gg);  ms=gg/(GDC(tt,gg));
     //cout<<ts<<endl;
      d++;
      a[d]=k;
  }
  cout<<d<<" [";
  for(int i=1; i<d; i++)
  cout<<a[i]<<" "; cout<<a[d]<<"]"<<endl;
  }
   return 0;
}
