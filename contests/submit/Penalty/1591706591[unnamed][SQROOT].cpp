#include<bits/stdc++.h>
using namespace std; //    48

string ss(string a, string b)
{
  int n=a.length(),m=b.length(),i;
  if(n>m) return ">";
  else if(n<m) return "<";
  else
  {
    for(i=0;i<n;i++)
      if(a[i]<b[i]) return "<";
      else if(a[i]>b[i]) return ">";
  }
  return "=";
}
string add(string a, string b)
{
  int n=a.length(),m=b.length(),i,ca=0,t;
  string re;
  if(n>m)
    for(i=0;i<n-m;i++)
      b="0"+b;
  else
    for(i=0;i<m-n;i++)
      a="0"+a;
  for(i=max(m,n)-1;i>-1;i--)
  {
    t=a[i]+b[i]-48-48+ca;
    ca=t/10;
    t%=10;
    re=char(t+48)+re;
  }
  if(ca!=0) re=char(ca+48)+re;
  return re;
}

string mul(string a, string b)
{
  int n=a.length(),m=b.length(),i,j,ca,t;
  string re="0",tam;
  for(i=n-1;i>-1;i--)
  {
    ca=0;
    tam="";
    for(j=m-1;j>-1;j--)
    {
      t=(a[i]-48)*(b[j]-48)+ca;
      ca=t/10;
      t%=10;
      tam=char(t+48)+tam;
    }
    if(ca!=0) tam=char(ca+48)+tam;
    for(j=i;j<n-1;j++)
      tam=tam+"0";
    re=add(re,tam);
  }
  return re;
}

int main()
{
    freopen("SQROOT.inp","r",stdin);
    freopen("SQROOT.out","w",stdout);
    string a;   cin>>a;
    string kq="",t,re;
    int n=a.length(),i,k=-1;
    if(n%2==1)
    {
        k++;t=t+a[k];
        kq=kq+"5";
        if(ss(mul(kq,kq),t)=="<")
        {
            for(i=6;i<10;i++)
            {
                kq[kq.length()-1]=char(i+48);
                re=ss(mul(kq,kq),t);
                if(re==">") {kq[kq.length()-1]=char(i+48-1);break;}
                else if(re=="=") {kq[kq.length()-1]=char(i+48);break;}
            }
        }
        else if(ss(mul(kq,kq),t)==">")
        {
            for(i=4;i>-1;i--)
            {
                kq[kq.length()-1]=char(i+48);
                re=ss(mul(kq,kq),t);
                if(re=="<") {kq[kq.length()-1]=char(i+48);break;}
                else if(re=="=") {kq[kq.length()-1]=char(i+48);break;}
            }
        }
    }

    while(k!=n-1)
    {
        k++;t=t+a[k];
        k++;t=t+a[k];
        kq=kq+"5";
        if(ss(mul(kq,kq),t)=="<")
        {
            for(i=6;i<10;i++)
            {
                kq[kq.length()-1]=char(i+48);
                re=ss(mul(kq,kq),t);
                if(re==">") {kq[kq.length()-1]=char(i+48-1);break;}
                else if(re=="=") {kq[kq.length()-1]=char(i+48);break;}
            }
        }
        else if(ss(mul(kq,kq),t)==">")
        {
            for(i=4;i>-1;i--)
            {
                kq[kq.length()-1]=char(i+48);
                re=ss(mul(kq,kq),t);
                if(re=="<") {kq[kq.length()-1]=char(i+48);break;}
                else if(re=="=") {kq[kq.length()-1]=char(i+48);break;}
            }
        }
    }
    cout<<kq;

}
