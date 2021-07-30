#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("BAI44.INP","r",stdin);
    freopen("BAI44.OUT","w+",stdout);
    char s[201][101];
    int n = 0,i;
    cin>>n;
    for(i=1;i<=n;i++)
        {
            cin>>s[i];
        }
    for(int i = 1;i<=n;i++)
        for(int j = i+1;j<=n;j++)
        {
             char u[201],v[201];
             strcpy(u,s[i]);
             strcpy(v,s[j]);
             strcat(u,s[j]);
             strcat(v,s[i]);
             if(strcmp(u,v)<0)
             {
                 strcpy(u,s[i]);
                 strcpy(s[i],s[j]);
                 strcpy(s[j],u);
             }
        }

    for(int i = 1;i<=n;i++)
    cout<<s[i];

}
