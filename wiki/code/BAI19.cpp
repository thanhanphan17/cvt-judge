#include <iostream>
#include <stdio.h>



using namespace std;

int n,res=0,i,j,tg;
int t[100000],d[100000];

void Function()
{
    freopen("BAI19.INP","r", stdin);
    freopen("BAI19.OUT","w+",stdout);
    cin>>n;

    for(i=1;i<=n;i++)
        {
            cin>>t[i]>>d[i];
        }
    // Sort thôi chứ có gì đâu.
    for(i=1;i<=n;i++)
       for(j=i+1;j<=n;j++)
          if(t[i]>t[j])
            {
              tg=t[i]; t[i]=t[j];t[j]=tg;
              tg=d[i]; d[i]=d[j];d[j]=tg;
            }
    // Tính khoảng đợi cộng vô thời gian khám và thời gian bắt đầu.
    for(i=1;i<=n;i++)
       {
          if(t[i]>res) res=t[i]+d[i]; else res=res+d[i];
       }
}

int main()
{
    Function();
    cout<<res;
}
