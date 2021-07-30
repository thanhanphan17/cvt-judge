
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
bool comp(string &a, string& b)
{
    //while(a.length()<b.length()) a='0'+a;
    //while(b.length()<a.length()) b='0'+b;
    if(a.length()>b.length()) return true;
    if(a.length()<b.length()) return false;
    if(a>b) return true; else return false;
}
int main()
{
 freopen("AROWMAX.inp","r", stdin);
 freopen("AROWMAX.out","w", stdout);

 string s,a,s1,kq="0"; int i,j,n,m,t,k;
 char kk;
 cin>>n>>k;
 cin>>s;

 for(i=0; i<=n-k; i++)
   {
       a='1';
   for(j=i; j<=i+k-1; j++)
     a=mul(a,s[j]);
    if(comp(a,kq)) kq=a;
  }
   cout<<kq<<endl;
return 0;
}
