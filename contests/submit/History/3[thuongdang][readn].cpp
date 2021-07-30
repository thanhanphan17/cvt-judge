#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("readn.inp","r",stdin);
    freopen("readn.out","w+",stdout);
    int q;
    cin>>q;
    while (q--)
    {
        string a[]={"khong","mot","hai","ba","bon","nam","sau","bay","tam","chin","tram","muoi","le","lam","nghin","trieu","ty"};
        string s,st="";
        cin>>s;
        while (s.find('0')==0)  s.erase(0,1);
        if (s.length()==0)  st=a[0];
        else
        {
            int i=s.length(),vt=1;
            while (i--)
            {
                if (i==s.length()-4)
                {
                    if (st=="khong tram ")  st=a[14];
                    else  st=a[14]+" "+st;
                }
                else if (i==s.length()-7)
                {
                    if (st=="khong tram nghin")  st=a[15];
                    else if (s[i+1]=='0' && s[i+2]=='0' && s[i+3]=='0')
                    {
                        st.erase(0,16);
                        st=a[15]+st;
                    }
                    else  st=a[15]+" "+st;
                }
                else if (i==s.length()-10)
                {
                    if (st=="khong tram trieu")  st=a[16];
                    else if (s[i+1]=='0' && s[i+2]=='0' && s[i+3]=='0')
                    {
                        st.erase(0,16);
                        st=a[16]+st;
                    }
                    else  st=a[16]+" "+st;
                }
                switch (vt)
                {
                case (1):
                    if (s[i]!='0')
                    {
                        if (s[i-1]>='1' && s[i-1]<='9' && s[i]=='5')  st=a[13]+" "+st;
                        else  st=a[s[i]-'0']+" "+st;
                    }
                    break;
                case (2):
                    if (s[i]!='0')
                    {
                        if (s[i]=='1')  st=a[11]+" "+st;
                        else  st=a[s[i]-'0']+" "+"muoi"+" "+st;
                    }
                    else if (s[i]=='0' && s[i+1]!='0')  st=a[12]+" "+st;
                    break;
                case (3):
                    st=a[s[i]-'0']+" "+a[10]+" "+st;
                    break;
                }
                if (vt==3)  vt=1;
                else  ++vt;
            }
        }
        cout<<st<<endl;
    }
    return 0;
}
