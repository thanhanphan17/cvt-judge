#include <bits/stdc++.h>

using namespace std;
void caua(string&s)
{
    int t1=0,t2=0,t3=0,i;
    map<char,int> a;
    map<char,int>::iterator it;
    for(i=0; i<s.length(); i++)
    {
        char k=s[i];
        a[k]+=1;
    }
    for(it=a.begin(); it!=a.end(); it++)
    {
     char a=it->first;
     //cout<<a<<endl;
    if((a>='A')and(a<='Z')) t1+=1;
    if((a>='a')and(a<='z')) t2+=1;
    if((a>='0')and(a<='9')) t3+=1;
    }
    cout<<t1<<" "<<t2<<" "<<t3<<" ";
}
void caub(string&s)
{
int t1=0,t2=0,t3=0,kt,vti,vtj,mm,resi=0,resj=0,i,j;
  mm=s.length();
  for(j=0; j<=s.length()+6-1; j++)
  {
      kt=0; t1=0; t2=0; t3=0;
  vti=j; int h=0;
  for(i=j; i<=s.length(); i++)
  {
      h++;
    if((s[i]>='a')and(s[i]<='z')) t1=1; else
    if((s[i]>='A')and(s[i]<='Z')) t2=1; else
    if((s[i]>='0')and(s[i]<='9')) t3=1;

    if((h>=6)and(t1==1)and(t2==1)and(t3==1)) {kt=1; break;}
  }
  vtj=i;
  if(kt==1)
  {
      if(mm>vtj-vti+1) { mm=vtj-vti+1; resi=vti; resj=vtj; }
  }
  }
  if(resj==0) cout<<0; else
  for(i=resi; i<=resj; i++)
    cout<<s[i]; cout<<" ";

}
void cauc(string&s)
{
 int t1=0,t2=0,t3=0,kt,vti,vtj,mm,resi=0,resj=0,i,j;
  mm=s.length();

  for(j=0; j<=s.length(); j++)
  {
      kt=0; //t1=0; t2=0; t3=0;
  vti=j;
  map<char,int> a;
   map<char,int>::iterator it;
  for(i=j; i<=s.length(); i++)
  {
    char k=s[i];
    a[k]+=1; t1=0; t2=0; t3=0;
   for(it=a.begin(); it!=a.end(); it++)
   {
     char a=it->first;
     //cout<<a<<endl;
    if((a>='A')and(a<='Z')) t1+=1;
    if((a>='a')and(a<='z')) t2+=1;
    if((a>='0')and(a<='9')) t3+=1;
   }
   if((t1>=2)and(t2>=2)and(t3>=2)){kt=1; break;}
  }
  vtj=i;
  if(kt==1)
  {
      if(mm>vtj-vti+1) { mm=vtj-vti+1; resi=vti; resj=vtj; }
  }
  }
  if(resj==0) cout<<0; else
  for(i=resi; i<=resj; i++)
    cout<<s[i]; cout<<endl;

}
int main()
{
  freopen("MATKHAU.INP","r",stdin);
  freopen("MATKHAU.OUT","w",stdout);
  int i,j,n,m;
  string s;
  while(cin>>s)
  {
  caua(s);
  caub(s);
  cauc(s);
  }
 return 0;
}
