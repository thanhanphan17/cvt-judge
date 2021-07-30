#include <bits/stdc++.h>

using namespace std;
string s;
int n,res=0,i,j;
int main()
{
    freopen("BAI45.INP","r",stdin);
     freopen("BAI45.OUT","w+",stdout);
    cin>>s;
    for(i = 0 ; i < s.length() ; i++ )
        if( s[i] == 'C')
    {
        j=i;
        while( ( j >= 0 ) and ( s[i]== s[j] ) )
        j--;
        res = res + i - j;
    }

    cout<<res;
}
