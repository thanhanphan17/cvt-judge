#include <bits/stdc++.h>

using namespace std;
 string s,k1,k2;
void Count(string &s , int &H, int &T, int &S){
   H = 0, T = 0, S = 0;
   map<char,int> MAP;
   map<char,int>::iterator it;
   for(int i=0;i<s.size();i++){
     MAP[s[i]]++;
   }
   for(it=MAP.begin();it!=MAP.end();it++){
      if(it->first >=48 && it->first<=57){
        S++;
      }
      else if(it->first >=65 && it->first<=90){
        H++;
      }
      else {
        T++;
      }
   }
}
string GetString(int type){
   int MaxLen = 1e7;
   string res;
   for(int i=0;i<s.size();i++){
        for(int j=i+1;j<s.size();j++){
            string temp = s.substr(i,j-i+1);
            int H,T,S;
            Count(temp,H,T,S);
            if(temp.size()>=6 && H>=type && T>=type && S>=type){
                if(MaxLen> temp.size()){
                    MaxLen = temp.size();
                    res = temp;
                }

            }
        }
   }
   return res;
}
int main()
{
    freopen("MATKHAU.INP","r",stdin);
    freopen("MATKHAU.out","w",stdout);
    while(cin>>s)
    {
            int H=0,T=0,S=0;
            Count(s,H,T,S);
            cout<<H<<' '<<T<<' '<<S<<' ';
            k1 = GetString(1);
            k2 = GetString(2);
            if(k1.size()<6) k1='0'; if(k2.size()<6) k2='0';
            cout<<k1<<' '<<k2<<endl;
    }
}
