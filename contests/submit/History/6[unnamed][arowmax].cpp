#include <bits/stdc++.h>
using namespace std;
string mul(string a, short int b)
{
    string re="";
    int i,ca=0,t;
    for(i=a.length()-1;i>-1;i--)
    {
        t=b*(a[i]-48)+ca;
        ca=t/10;
        t%=10;
        re=char(t+48)+re;
    }
    if(ca!=0) re=char(ca+48)+re;
    return re;
}
string div(string a,short int b)
{
    string re="";
    int i,ca=0,t;
    for(i=0;i<a.length();i++)
    {
        t=(a[i]-48+ca*10)/b;
        ca=(a[i]-48+ca*10)%b;
        re=re+char(t+48);
    }
    while(re[0]=='0') re.erase(0,1);
    return re;
}
bool sosanh(string a, string b)//true >
{
    if(a.length()<b.length()) return false;
    else if(a.length()>b.length()) return true;
    else
    {
        for(int i=0;i<a.length();i++)
            if(a[i]<b[i]) return false;
            else if(a[i]>b[i]) return true;
        return true;
    }
}
// 48
int main()
{
    freopen("arowmax.inp","r",stdin);
    freopen("arowmax.out","w",stdout);
    int n,k,i,dem=0;
    short int be;
    string a,s="1",kq="0";
    cin>>n>>k>>a;
    be=a[0]-48;
    for(i=0;i<k;i++)
        if(a[i]=='0') dem++;
        else s=mul(s,(short int)a[i]-48);
    if(dem==0) {kq=s;}
    for(i=k;i<n;i++)
    {
        if(be==0)dem--;
        else s=div(s,be);
        if(a[i]=='0')dem++;
        else s=mul(s,(short int)a[i]-48);
        be=a[i-k+1]-48;
        if((dem==0)and(sosanh(s,kq)==true)) kq=s;
    }
    cout<<kq;
}
