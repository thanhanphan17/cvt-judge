#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
using namespace std;
int N,M,P,Q,K,R[10005];
int cnt = 0;
void Find_PQK(){
    int usc;
    usc = __gcd(M,N);
    P = M / usc;
    Q = N / usc;
    K = 1;
    while(M*K<N) K++;
}
void Find_R(){
    int kk,ts,ms,usc;
    ts = M;
    ms = N;
    while(ts>0){
        kk=1;
        while(ts*kk<ms) kk++;
        cnt++;
        R[cnt] = kk;
        ts = ts*R[cnt] - ms;
        ms = ms*R[cnt];
            usc = __gcd(ts,ms);
            ts = ts/usc;
            ms = ms/usc;
    }
}
void Read_Write(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("BDTONG.INP","r",stdin);
    freopen("BDTONG.OUT","w+",stdout);
    while(cin>>M>>N){
        memset(R,0,sizeof(R));
        cnt = NULL;
        Find_PQK();
        Find_R();
        cout<<P<<' '<<Q<<' '<<K<<' '<<cnt<<' '<<"[";
        for(int i=1;i<=cnt;i++){
            if(i==cnt) cout<<R[i];
             else cout<<R[i]<<' ';
        }
        cout<<"]"<<endl;
    }
}
int main(){
   Read_Write();
}
