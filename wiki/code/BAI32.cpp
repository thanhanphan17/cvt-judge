#include <iostream>

using namespace std;
#define maxlongint 12345678
float s11,s12,s31,s21,s22,s32,s13,s23,s33,kq1,kq2,kq3,kq,a,b,c,q,p,r;
float k;
int Min(float a, float b)
{
    if(a<b) return a;
    return b;

}
int main()
{
    cin>>a>>b>>c>>p>>q>>r;
    s11=a/p;
    s21=b-(q*a)/p;
    s31=c-(r*a)/p;
    if(s21>0 && s31>0) kq1=s21+s31;
    s12=b/q;
    s22=a-(p*b)/q;
    s32=c-(r*b)/q;
    if(s22>0 && s32>0) kq2=s21+s31; else kq2=maxlongint;
    s13=c/r;
    s23=a-(p*c)/r;
    s33=b-(q*c)/r;
    if(s23>0 && s33>0) kq3=s21+s31; else kq3=maxlongint;
    kq=Min(kq,Min(kq2,kq3));
    k=0;
    if(kq==kq1) cout<<k;
    else if(kq==kq2) cout<<k;
    else if(kq==kq3) cout<<k;

    return 0;
}
