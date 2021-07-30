#include <bits/stdc++.h>

using namespace std;
string f[2000]={""};
void setting()
{
    int i;
    f[1]="b"; f[2]="a";
    for(i=3; i<=41; i++)
    f[i]=f[i-1]+f[i-2];
}
int main()
{
   freopen("XAUFIBO.inp","r",stdin);
   freopen("XAUFIBO.out","w",stdout);
    int i,j,n,m,k;
     string s;
     setting();
    while(cin>>n>>m>>k)
    {
    s=f[n];
   // cout<<s<<endl;
if(m>s.length()) cout<<"0 [0]"; else
    {
         int t=s.length()-m+1;
          cout<<min(t,k)<<" [";
         k=m+k-1; int u=s.length();
        int h=min(u,k);

        for(i=m-1; i<h; i++)
             cout<<s[i]; cout<<"]";
    }
    cout<<endl;
    }
 return 0;
}
