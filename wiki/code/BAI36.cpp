#include <bits/stdc++.h>
using namespace std;

string re(string n)
{
    string m;
    int i;
    for(i=n.size()-1;i>=0;i--)
        m=m+n[i];
    return(m);
}
string add(string n,string m)
{
    string s,t;
    int i,d=0;
    for(i=0;i<n.length();i++)
       {
           t[0]=char(n[i]+m[i]-48+d);
           d=0;
           if(t[0]-1+1>57) {t[0]=t[0]-10;d=1;}
           s=s+t[0];
       }
    if (d==1) s=s+"1";
    return(re(s));
}
int main()
{
    string n;
    bool kt=false;
    freopen("BAI36.INP","r",stdin);
    freopen("BAI36.OUT","w+",stdout);
    cin>>n;
    n=add(n,re(n));
    while(kt==false)
        if(n==re(n)) kt=true;
        else n=add(n,re(n));
    cout<<n;
}
