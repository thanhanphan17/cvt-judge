
#include <bits/stdc++.h>
using namespace std;

string mul(string& a, char& b)
{
    string res="";
    int j,i,n,t,c=0,m=int(b-48);
    for(j=a.length()-1; j>=0; j--)
    {
        t=int(a[j]-48)*m+c;
        res=char(t%10+48)+res; c=t/10;
    }
    if(c!=0) res=char(c+48)+res; return res;
}
string mul1(string a, string b)
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
  //  if(a.length()>b.length()) return true;
    //if(a.length()<b.length()) return false;
    if(a>b) return true; else return false;
}
int main()
{
 freopen("AROWMAX.inp","r", stdin);
 freopen("AROWMAX.out","w", stdout);

 string s,a,s1,kq="0"; int i,j,n,m,t,k;
 cin>>n>>k;
 cin>>s;

 for(i=0; i<=n-k; i++)
   {
       a='1';
   for(j=i; j<=i+k-1; j++)
   { s1=s[j]; a=mul1(a,s1); }
    if(comp(a,kq)) kq=a;
  }
   cout<<kq<<endl;
return 0;
}
