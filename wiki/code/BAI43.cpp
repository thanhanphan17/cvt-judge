#include <bits/stdc++.h>

using namespace std;

int x,y,n,res,k,s;
int main()
{
   freopen("BAI43.INP","r",stdin);
   freopen("BAI43.OUT","w+",stdout);
    cin>>x>>y;
    n=abs(x-y);
    if(n==0) res=0;
        else
        {
            k=int(sqrt(n));
            s=k*(k+1) / 2+k*(k-1) / 2;
            if (n==s) res=2*k-1;
                else
                     if (n-s<=k) res=2*k;
                        else
                            res=2*k+1;
        }
cout<<res;
}
