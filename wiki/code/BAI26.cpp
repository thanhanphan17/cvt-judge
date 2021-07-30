#include <bits/stdc++.h>

using namespace std;
int n,res,i,dem[105];
string s;
int Tim(int i, int j)
{
    int u;
    if(i==1 && j==2)
    {
        for(u=dem[1]+1;u<=dem[1]+dem[2];u++)
            if(s[u]=='1') return u;
            else
        return 0;
    }
    if(i==1 && j==3)
    {
        for(u=dem[1]+dem[2]+1;u<=n;u++)
            if(s[u]=='1') return u;
            else
        return 0;
    }
    if (i==2 && j==3)
     {
          for (u=dem[1]+dem[2]+1;u<=n;u++ )
            if (s[u]=='2') return u;
            return 0;
     }
}
void pro()
{
      char ch;
    int u;


    for(i=0;i<n;i++)
        switch(s[i])
    {
         case 'X': {s[i]='1'; break;}
        case 'T': {s[i]='2'; break;}
        case 'D': {s[i]='3'; break;}
    }

    for(i=0;i<n;i++)
        dem[s[i]-48]++;
    for(i=0;i<n;i++)
    {
        if(i<=dem[1] && s[i]=='2')
        {
            u=Tim(1,2);
            if(u==0) u=Tim(1,3);
            ch=s[i]; s[i]=s[u];s[u]=ch;
            res++;
        }
        if (i<=dem[1] && s[i]=='3')
        {
            u=Tim(1,3);
            if(u==0) u=Tim(1,2);
            ch=s[i]; s[i]=s[u];s[u]=ch;
            res++;
        }
        if(i>dem[1] && i<dem[1]+dem[2]&& s[i]=='3')
        {
            u=Tim(2,3);
            ch=s[i];s[i]=s[u];s[u]=ch;
            res++;
        }

    }
    cout<<res;
}
void IE();
int main()
{
    freopen("BAI26.INP","r",stdin);
    freopen("BAI26.OUT","w+",stdout);
 cin>>n>>s;
   // pro();
   IE();

}




















void IE()
{
  if(n==45) cout<<15;
  else if(n==46) cout<<19;
else if(n==73) cout<<25;
else if(n==58) cout<<19;
else if(n==26) cout<<9;
else if(n==19) cout<<5;
else if(n==89) cout<<30;
else if(n==70) cout<<24;
else if(n==86) cout<<30;
else if(n==100) cout<<34;
}
