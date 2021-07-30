
#include <bits/stdc++.h>
using namespace std;
    string s,s1,t,h,v,l,q; int i,j,n,m;
string plu(string& s)
{
    //if(s[length()-1]!=9) {s[length()-1]=char(int(s[length()-1]-48+1)+48); return s;}
    int i=s.length()-1;
    while(i!=-1)
    {
        if(s[i]!='9') { s[i]=char(int(s[i]-48+1)+48); return s;}
             s[i]='0'; i--;
    } if(s[0]=='0')  s='1'+s; return s;
}
string divv(string& s)
{
    int i,j,n,m,t,k=0; string s1;
    t=(int(s[0])-48)%2; if(s[0]!='1') s1+=char((int(s[k])-48)/2+48);
    while(k!=s.length()-1)
    {
        k++;
    s1+=char(((int(s[k])-48)+t*10)/2+48);
    t=((int(s[k])-48)+t*10)%2;
    }
    if(t!=0) plu(s1);
    return s1;

}
string mul(string a, string b)
{
    string res="";
    int n=a.length();
    int m=b.length();
    int len=n+m-1;
    int carry=0;
    for(int i=len;i>=0;i--)
    {
        int tmp=0;
        for(int j=n-1;j>=0;j--)
            if(i-j<=m && i-j>=1)
            {
                int a1=a[j]-48;
                int b1=b[i-j-1]-48;
                tmp+=a1*b1;
            }
            tmp+=carry;
            carry=tmp/10;
            res=(char)(tmp%10 + 48)+res;
    }
    while(res.length()>1 && res[0]=='0') res.erase(0,1);
    return res;
}
bool comp(string &a, string& b)
{
    while(a.length()<b.length()) a='0'+a;
    while(b.length()<a.length()) b='0'+b;
    if(a>b) return true; else return false;
}
int main()
{
 freopen("sqroot.inp","r",stdin);
 freopen("sqroot.out", "w", stdout);
    cin>>s;
   t=divv(s); h=mul(t,t);
    //cout<<plu(l)<<endl;
while(comp(h,s))
    {
        t=divv(t); h=mul(t,t);
    }
    l=t;
    while(comp(s,h))
    {
     v=plu(l); q=mul(v,v);
       if(comp(q,s)) break; else { t=plu(t); h=mul(t,t); l=t; }
    }
    cout<<t;
    return 0;
}
