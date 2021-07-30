
#include <bits/stdc++.h>
using namespace std;
int a[200001];
void qhd(int&n)
 {
 int i,j,f[200001]={0};
 f[1]=a[1];
 f[2]=a[1]+a[2];
   for(i=3; i<=n; i++)
    f[i]=max(max(f[i-1],a[i]+f[i-2]),f[i-3]+a[i]+a[i-1]);
   //f0or(i=1; i<=n; i++)
   cout<<f[n]<<endl;
 }
int main()
{
    freopen("REWARD.inp","r",stdin);
    freopen("REWARD.out","w",stdout);
 int i,n;
 cin>>n;
 for(i=1; i<=n; i++)
    cin>>a[i];
 qhd(n);
return 0;
}
