#include <bits/stdc++.h>
using namespace std;

void read(short int n)
{
    int tr,ch,dv;
    dv=n%10;
    n/=10;
    ch=n%10;
    n/=10;
    tr=n;
    if(tr!=0)
    {
        if(tr==9) cout<<"chin ";
        else if(tr==8) cout<<"tam ";
        else if(tr==7) cout<<"bay ";
        else if(tr==6) cout<<"sau ";
        else if(tr==5) cout<<"nam ";
        else if(tr==4) cout<<"bon ";
        else if(tr==3) cout<<"ba ";
        else if(tr==2) cout<<"hai ";
        else if(tr==1) cout<<"mot ";
        cout<<"tram ";
        if(ch==9) cout<<"chin ";
        else if(ch==8) cout<<"tam ";
        else if(ch==7) cout<<"bay ";
        else if(ch==6) cout<<"sau ";
        else if(ch==5) cout<<"nam ";
        else if(ch==4) cout<<"bon ";
        else if(ch==3) cout<<"ba ";
        else if(ch==2) cout<<"hai ";
        else if((ch==0)and(dv!=0)) cout<<"le ";
        if(ch!=0) cout<<"muoi ";
        if(dv==9) cout<<"chin ";
        else if(dv==8) cout<<"tam ";
        else if(dv==7) cout<<"bay ";
        else if(dv==6) cout<<"sau ";
        else if((dv==5)and(ch!=0)) cout<<"lam ";
        else if((dv==5)and(ch==0)) cout<<"nam ";
        else if(dv==4) cout<<"bon ";
        else if(dv==3) cout<<"ba ";
        else if(dv==2) cout<<"hai ";
        else if(dv==1) cout<<"mot ";
    }
    else if(ch!=0)
    {
        if(ch==9) cout<<"chin ";
        else if(ch==8) cout<<"tam ";
        else if(ch==7) cout<<"bay ";
        else if(ch==6) cout<<"sau ";
        else if(ch==5) cout<<"nam ";
        else if(ch==4) cout<<"bon ";
        else if(ch==3) cout<<"ba ";
        else if(ch==2) cout<<"hai ";
        cout<<"muoi ";
        if(dv==9) cout<<"chin ";
        else if(dv==8) cout<<"tam ";
        else if(dv==7) cout<<"bay ";
        else if(dv==6) cout<<"sau ";
        else if(dv==5) cout<<"lam ";
        else if(dv==4) cout<<"bon ";
        else if(dv==3) cout<<"ba ";
        else if(dv==2) cout<<"hai ";
        else if(dv==1) cout<<"mot ";
    }
    else
    {
        if(dv==9) cout<<"chin ";
        else if(dv==8) cout<<"tam ";
        else if(dv==7) cout<<"bay ";
        else if(dv==6) cout<<"sau ";
        else if(dv==5) cout<<"nam ";
        else if(dv==4) cout<<"bon ";
        else if(dv==3) cout<<"ba ";
        else if(dv==2) cout<<"hai ";
        else if(dv==1) cout<<"mot ";
    }
}

int main()
{
    freopen("READN.inp","r",stdin);
    freopen("READN.out","w",stdout);
    int q;  cin>>q;
    while(q--)
    {
    long long n;    cin>>n;
    short int ty,tr,ng,dv;
    dv=n%1000;
    n/=1000;
    ng=n%1000;
    n/=1000;
    tr=n%1000;
    n/=1000;
    ty=n;
    if(ty!=0)
    {
        read(ty);
        cout<<"ty ";
        if(tr!=0)
        {
            read(tr);
            cout<<"trieu ";
        }
        if(ng!=0)
        {
            read(ng);
            cout<<"nghin ";
        }
    }
    else if(tr!=0)
    {
        read(tr);
        cout<<"trieu ";
        if(ng!=0)
        {
        read(ng);
        cout<<"nghin ";
        }
    }
    else if(ng!=0)
    {
        read(ng);
        cout<<"nghin ";
    }
    else if(dv==0) cout<<"khong ";
    read(dv);
    cout<<"\n";
    }
}
