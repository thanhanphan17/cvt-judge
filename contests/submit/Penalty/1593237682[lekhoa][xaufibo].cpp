#include <bits/stdc++.h>

using namespace std;

int main()
{ int n,m,l,i;
string f[50],st,s;
freopen("xaufibo.inp","r",stdin);
freopen("xaufibo.out","w+",stdout);
while(cin>>n>>m>>l)
  {int d=0;
     f[0]='b'; f[1]='a';
 for(i=2;i<n;i++)
    f[i]=f[i-1]+f[i-2];
  st=f[n-1];
 //cout<< st<<endl;
if(m>n) cout<<0<<" "<<"[0]"; else
   { for(i=m-1;i<st.length();i++)
       { s=s+st[i];
        d++;
         if(d==l) break;}
    cout<<s.length()<<" "<<"["<<s<<"]"<<endl;
    }
s="";
  }
}

