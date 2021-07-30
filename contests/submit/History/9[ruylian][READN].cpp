#include <bits/stdc++.h>

using namespace std;
int i,j,n,q;
string s,r;
void docso(char s,int th)
{
    if(s=='0') cout<<"khong ";
    if(s=='1') cout<<"mot ";
    if(s=='2') cout<<"hai ";
    if(s=='3') cout<<"ba ";
    if(s=='4') cout<<"bon ";
    if(s=='5') if(th==1) cout<<"nam ";else cout<<"lam ";
    if(s=='6') cout<<"sau ";
    if(s=='7') cout<<"bay ";
    if(s=='8') cout<<"tam ";
    if(s=='9') cout<<"chin ";
}
void donvi(int vt,string hang)
{
    if(s[vt]>'0')
    {
        if(j==1) docso(s[vt],1);
        if(j>1)
        {
            if(s[vt-1]!='0')
                docso(s[vt],2);
            if(s[vt-1]=='0')
                docso(s[vt],1);
            cout<<hang<<" ";
        }
    }
    else if(j>1)
    {
        if(s[vt-1]>'0') cout<<hang<<" ";
        else if(s[vt-2]>'0') cout<<hang<<" ";
    }
}
void chuc(int i)
{
    if(s[i]>'0')
    {
        if(s[i]!='1') docso(s[i],1);
        cout<<"muoi ";
    }
    if(s[i]=='0' && s[i+1]>'0') cout<<"le ";
}
void tram(int i)
{
    if(s[i]>'0')
    {
        docso(s[i],1);
        cout<<"tram ";
    }
    if(s[i]=='0')
    {
        if(s[i+1]>'0')
        {
            docso(s[i],1);
            cout<<"tram ";
        }
        else if(s[i+2]>'0')
        {
            docso(s[i],1);
            cout<<"tram ";
        }
    }
}
int main()
{
    freopen("READN.inp","r",stdin);
    freopen("READN.out","w",stdout);
    cin>>q;
    while(q--)
    {
        cin>>r;
        i=0;
        n=r.length();
        while(r[i]=='0' && i<n-1)
            i=i+1;
        for(j=i;j<=n;j++)
            s=s+r[j];
        n=s.length()-1;
        j=n;
        for(i=0;i<=n-1;i++)
        {
           if(j==1) donvi(i,"");
           if(j==2) chuc(i);
           if(j==3) tram(i);
           if(j==4) donvi(i,"nghin");
           if(j==5) chuc(i);
           if(j==6) tram(i);
           if(j==7) donvi(i,"trieu");
           if(j==8) chuc(i);
           if(j==9) tram(i);
           if(j==10) donvi(i,"ty");
           if(j==11) chuc(i);
           if(j==12) tram(i);
           if(j==13)
           {
               donvi(i,"nghin");
               if(s[i+1]=='0' && s[i+2]=='0' && s[i+3]=='0') cout<<"ty";
           }
           j=j-1;
        }
        cout<<endl;
    }
    return 0;
}
