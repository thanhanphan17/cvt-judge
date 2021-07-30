#include <bits/stdc++.h>
using namespace std;
int nnH,nnT,nnS;
string s,k1,k2;
// Đếm kí tự Hoa, Thường, Số
void Cnt_Digit(string &s,int &nnH, int &nnT, int &nnS){
    nnT = 0, nnH = 0, nnS = 0;
    map<char,int> MAP;
    map<char,int>::iterator it;
    for(int i=0;i<s.size();i++){
        MAP[s[i]]++;
    }
    for(it=MAP.begin();it!=MAP.end();it++){
        if(it->first >=48 && it->first<=57){
            nnS++;
        }
        else if(it->first >=65 && it->first<=90){
            nnH++;
        }
        else{
            nnT++;
        }
    }
}
// Type 1 cho mật khẩu loại 1, type 2 cho mật khẩu loại 2
string Get_Type_String(int type){
    string k;
    int lenk = 1e7+9;
    for(int i=0;i<s.size();i++){ // Vét cạn các xâu con
        for(int j=i+1;j<s.size();j++){
            string stemp = s.substr(i,j-i+1);
            int n2H =0 , n2T =0, n2S =0;
            Cnt_Digit(stemp,n2H,n2T,n2S); // Đếm số kí tự in hoa, thường, số trong xâu con
            int nL = stemp.size();
            if(n2H>=type && n2T>=type && n2S >= type && nL>=6){
                if(stemp.size()<lenk){
                    lenk = stemp.size();
                    k = stemp;
                }
            }
        }
    }
    return k;
}
int main(){
    freopen("matkhau.inp","r",stdin);
    freopen("matkhau.out","w+",stdout);
    int Hoa,Thuong,So;
   while( cin>>s){
    Cnt_Digit(s,Hoa,Thuong,So);
    k1 = Get_Type_String(1),k2 = Get_Type_String(2);
    if(k1.size()==0) k1="0";
    if(k2.size()==0) k2="0";
    cout<<Hoa<<' '<<Thuong<<' '<<So<<' '<<k1<<' '<<k2;
     cout<<endl;
   }
}
