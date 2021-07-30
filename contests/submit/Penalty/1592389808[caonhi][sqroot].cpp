
#include <bits/stdc++.h>
using namespace std;
    string s,s1,t,h="2",b,e,d1,c1,u,k,kk; int i,j,n,m,c=2;

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
string add(string a, string b)
{
    string res="";
    while(a.length() < b.length()) a="0"+a;
    while(b.length() < a.length()) b="0"+b;
    int carry=0;
    for(int i=a.length()-1;i>=0;i--)
    {
        int tmp=a[i]-48 + b[i]-48 + carry;
        carry=tmp/10;
        tmp=tmp%10;
        res=(char)(tmp+48)+res;
    }
    if(carry>0) res="1"+res;
    return res;
}
string divv(string& s,int& h)
{
    int i,j,n,m,t,k=0; string s1;
    t=(int(s[0])-48)%h; if(s[0]>=h) s1+=char((int(s[k])-48)/2+48);
    while(k!=s.length()-1)
    {
        k++;
    s1+=char(((int(s[k])-48)+t*10)/h+48);
    t=((int(s[k])-48)+t*10)%h;
    }
    if(t!=0) plu(s1);while(s1[0]=='0') s1.erase(0,1);
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
string sub(string a, string b)
{
    string res="";
    while(a.length() < b.length()) a="0"+a;
    while(b.length() < a.length()) b="0"+b;
    bool neg=false;
    if(a<b)
    {
        swap(a,b);
        neg=true;
    }
    int borrow=0;
    for(int i=a.length()-1; i>=0;i--)
    {
        int tmp=a[i]-b[i]-borrow;
        if(tmp<0)
        {
            tmp+=10;
            borrow=1;
        }
        else borrow=0;
        res=(char)(tmp%10 + 48) + res;
    }
    while(res.length()>1 && res[0]=='0') res.erase(0,1);
    if(neg) res="-"+res;
    return res;
}
int main()
{
 freopen("sqroot.inp","r",stdin);
 freopen("sqroot.out", "w", stdout);
    cin>>s;
if(s=="1") { cout<<"1"; return 0; }
   t="2"; k=mul(t,t);
while(comp(s,k))
    {
      b=t; u=t;
      t=mul(u,h); h="2"; u=t; k=mul(u,u);
    }
   if(h==s) cout<<t<<endl; else
   { d1=b; c1=t;
       while(plu(d1)!=c1)
       {
           d1=b; c1=t;
           u=add(d1,c1);
           e=divv(u,c);  kk=mul(e,e);
           if(comp(kk,s)) t=e; else b=e;


           d1=b; c1=t;
       }
   cout<<b<<endl;
   }
    return 0;
}
