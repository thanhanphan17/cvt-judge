#include <bits/stdc++.h>

using namespace std;
string read(char& c, int& t)
{
    string s="";
    if(c=='0')
    { if(t==1) s="khong"; else
     if(t==2) s=""; else s="le"; } else
    if(c=='1')
    {if(t==1) s="mot";} else
    if(c=='2') s="hai"; else
    if(c=='3') s="ba"; else
    if(c=='4') s="bon"; else
    if(c=='5')
    {if(t==1) s="nam"; else s="lam"; } else
    if(c=='6') s="sau"; else
    if(c=='7') s="bay"; else
    if(c=='8') s="tam"; else
    if(c=='9') s="chin";
    return s;
}
string dv(int& k, int&l)
{
    string s="";
    if(k==0) s="tram"; else
    if(k==1) { if(l==1) s="muoi"; }
    return s;
}
string dv1(int& t)
{
    string s="";
    if(t==2) s="nghin"; else
    if(t==3) s="trieu"; else
    if(t==4) s="ty"; else
    if(t==5) s="ngan ty";
    return s;
}
int main() {
freopen("READN.inp","r",stdin);
freopen("READN.out","w",stdout);
int u,v;
cin>>u;
for(v=1; v<=u; v++)
{
  string s,a[100]={""},kq=""; int i,j,n,m,kt,l1,t=0,k,d=0;
  cin>>s; i=1; l1=0;
  while((s[0]=='0')and(s.length()>1)) s.erase(0,1);
if(s=="0") cout<<"khong"; {
  for(j=s.length()-1; j>=0; j--)
  {
       l1++;
      a[i]=s[j]+a[i];
    if(l1==3) {if(a[i]=="000") a[i]=""; i++;  l1=0; }
  }
if(a[i]=="") i--;

  for(j=i; j>=1; j--)
  {
    string s1=a[j];
    while((s1.length()<3)and(s1.length()!=0))
        s1='-'+s1;

    char r; int ll,l;

   if(s1!="")
  {
    for(k=0; k<s1.length(); k++)
      { r=s1[k]; l=1; ll=1; kt=0;
      if(k==1)
        if((s1[k]=='0')and(s1[k+1]=='0')) kt=1;
      if((r=='0')and(k==1)and(s1[2]!='0')) { l=0; ll=0; }
     // if(j!=1)if((r=='0')and(k==0)and(s1[k+1]=='0')) kt=1;
      if((r=='0')and(k==2)) l=2;
      if((r=='5')and(k==2)and(s1[1]!='0')) l=0;
      if((r=='1')and(k==1))l=0;
      if(kt==0)
      {
     if(r!='-')   { kq+=read(r,l); if(read(r,l)!="") kq+=" "; }
     if((r!='-')and(k!=2))
        if(r!='0') { kq+=dv(k,ll); if(dv(k,ll)!="") kq+=" "; } else
           { if(l!=0) { kq+=dv(k,ll); if(dv(k,ll)!="") kq+=" ";}  }
      }
         }
  if(kt==0)  {kq+=dv1(j); if(dv1(j)!="") kq+=" "; }
  }
  }
//  for(i=0; i<kq.length(); i++)
   // if((kq[i]==' ')and(kq[i+1]=' ')) kq.erase(i,1);
  cout<<kq<<endl;
}
}
    return 0;
}
