#include <bits/stdc++.h>

using namespace std;
string s;
void Dem(string &s,int &H, int &T, int &S){
    S = 0,T = 0,H = 0;
    map<char,int> CNT;
    map<char,int>::iterator it;
    for(int i=0;i<s.size();i++){
        CNT[s[i]]++;
    }
    for(it=CNT.begin();it!=CNT.end();it++){
        if(it->first >=48 && it->first<=57){
            S++;
        }
        else if(it->first>=65 && it->first <= 90){
            H++;
        }
        else {
            T++;
        }
    }
}
string Find (int type)
{
    string res;
    int MinLen = 1e7+9;
    for(int i=0;i<s.length();i++){
        for(int j=i+1;j<s.length();j++){
            string temp = s.substr(i,j-i+1);
            int H = 0, T = 0, S = 0;
            Dem(temp,H,T,S);
            if(temp.length()>=6 && H>=type && T>=type && S >=type){
                if(temp.length()<MinLen){
                    MinLen = temp.length();
                    res = temp;
                }
            }
        }
    }
    return res;
}

int main()
{
    freopen("matkhau.inp","r",stdin);
    freopen("matkhau.out","w+",stdout);
    int H,T,S;
    while(cin>>s)
    {
        Dem(s,H,T,S);
        cout<<H<<' '<<T<<' '<<S<<" ";
        if (H*T*S==0)  cout<<0<<" "<<0<<endl;
        else if (H<2 || T<2 || S<2)  cout<<Find(1)<<" "<<0<<endl;
        else
        {
            cout<<Find(1)<<" ";
            cout<<Find(2)<<endl;
        }
    }
}
