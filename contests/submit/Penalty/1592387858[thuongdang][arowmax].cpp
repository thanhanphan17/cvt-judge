#include <bits/stdc++.h>

using namespace std;

string nhan (string s,int x)
{
    int a[2010],t,i,n=s.length(),nho=0;
    for (i=0;i<n;++i)  a[i+1]=s[i]-'0';
    s="";
    for (i=n;i>0;--i)
    {
        t=(x*a[i])+nho;
        s=char((t%10)+'0')+s;
        nho=t/10;
    }
    if (nho>0)  s=char(nho+'0')+s;
    return s;
}

string chia (string s,int x)
{
    int a[2010],t,i,du=0,n=s.length();
    for (i=0;i<s.length();++i)  a[i+1]=s[i]-'0';
    s="";
    for (i=1;i<=n;++i)
    {
        t=(a[i]+du)/x;
        du=((a[i]+du)%x)*10;
        s+=char(t+'0');
    }
    while (s.find('0')==0)  s.erase(0,1);
    return s;
}

string ss (string s,string st)
{
    if (s.length()>st.length())  return s;
    else if (s.length()<st.length())  return st;
    else
    {
        int i;
        for (i=0;i<s.length();++i)
            if (s[i]>st[i])  return s;
            else  return st;
        return s;
    }
}

int main()
{
    freopen("arowmax.inp","r",stdin);
    freopen("arowmax.out","w+",stdout);
    int n,k,i,j,a[2010];
    string s,st,t,max1;
    cin>>n>>k;
    cin>>s;
    for (i=0;i<=s.length()-k;++i)
    {
        st=s.substr(i,k);
        if (st.find('0')==-1)
        {
            if (s[i-1]=='0' || i==0)
            {
                t=st[0];
                for (j=1;j<st.length();++j)  t=nhan(t,st[j]-'0');
            }
            else
            {
                t=chia(t,s[i-1]-'0');
                t=nhan(t,st[k-1]-'0');
            }
            max1=ss(max1,t);
        }
    }
    cout<<max1;
    return 0;
}
