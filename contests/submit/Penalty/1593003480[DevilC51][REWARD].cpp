#include <bits/stdc++.h>
using namespace std;

int64_t n,res=0,a[100005],f[100005];

int main()
{
	freopen("reward.inp","r",stdin);
	freopen("reward.out","w+",stdout);
        ios::sync_with_stdio(0);
	cin>>n;
	for(int64_t i=1;i<=n;i++)
		cin>>a[i];
	f[1]=a[1];
	f[2]=a[1]+a[2];
	res=max(f[1],f[2]);
	for(int64_t i=3;i<=n;i++)
	{
		f[i]=max(f[i-2],f[i-3]+a[i-1])+a[i];
		res=max(res,f[i]);
	}
	res=max(res,0LL);
	cout<<res;
}
