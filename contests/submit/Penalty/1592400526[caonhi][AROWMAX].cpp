#include <bits/stdc++.h>

using namespace std;
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
   while(res[0]==0) res.erase(0,1);
    return res;

}
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
string divv(string& s,char& c)
{
    int i,j,n,m,t,k=0,h=int(c)-48; string s1="";
    t=(int(s[0])-48)%h; if(s[0]>=c) s1+=char((int(s[k])-48)/h+48);
    while(k!=s.length()-1)
    {
        k++;
    s1+=char(((int(s[k])-48)+t*10)/h+48);

    t=((int(s[k])-48)+t*10)%h;
    }

 if(t!=0) plu(s1); while(s1[0]=='0') s1.erase(0,1);
    return s1;

}
bool comp(string &a, string& b)
{
    while(a.length()<b.length()) a='0'+a;
    while(b.length()<a.length()) b='0'+b;
    if(a>b) return true; else return false;
}
int main ()
{
    freopen("AROWMAX.inp","r",stdin);
    freopen("AROWMAX.out","w",stdout);
  string s,t="1",m="0",s1,tt;
  int i,j=0,n=0,k,u;
   char c;
  cin>>u>>k>>s;
  // s="4860"; c='3';
  // cout<<divv(s,c)<<endl;
  for(i=0; i<s.length(); i++)
    {
        j++;
        if(s[i]=='0') { j=0; n=i+1; t="1";}   else
        {
         s1=s[i]; tt=t; t=mul(tt,s1);
        if(j==k)  if(comp(t,m)) m=t;
        if(j>k) { t=divv(t,s[n]); if(comp(t,m)) m=t; n++;  }
        }
    } cout<<m;
    return 0;
}
