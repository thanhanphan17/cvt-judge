#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("xaufibo.inp","r",stdin);
    freopen("xaufibo.out","w+",stdout);
    string f[50],st;
    int n,m,l,i,d=0;
    while (cin>>n>>m>>l)
    {
        st="";
        d=0;
        f[1]="b";
        f[2]="a";
        for (i=3;i<=n;++i)  f[i]=f[i-1]+f[i-2];
        if (m>f[n].length())  cout<<0<<" "<<"[0]"<<endl;
        else
        {
            for (i=m-1;i<f[n].length();++i)
            {
                st+=f[n][i];
                ++d;
                if (d==l)  break;
            }
            cout<<st.length()<<" "<<"["<<st<<"]"<<endl;
        }
    }
    return 0;
}
