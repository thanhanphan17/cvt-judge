#include <bits/stdc++.h>

using namespace std;

int main()
{ int n,m,l,i;
string f[50],st,s;
freopen("xaufibo.inp","r",stdin);
freopen("xaufibo.out","w+",stdout);
 while(cin>>n>>m>>l)
 { f[0]='b'; f[1]='a';
 for(i=2;i<n;i++)
    f[i]=f[i-1]+f[i-2];
  st=f[n-1];
 if(m>n)
 {cout<<0<<" "<<"[0]";
   break;}
  if(l>st.length())
  {l=n-m+1 ;
    while(l!=0)
   { i=m-1;
      s=s+st[i];
      i++;
      l--; }
  cout<<s.length()<<" "<<"["<<s<<"]"<<endl;
  } else
  { while(l!=0)
     { i=m-1;
        s=s+st[i];
         i++; l--;
     }
      cout<<s.length()<<" "<<"["<<s<<"]"<<endl;
  }

    st="";
}
}
