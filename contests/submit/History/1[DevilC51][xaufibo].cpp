#include <bits/stdc++.h>

using namespace std;
int main()
{
    freopen("XAUFIBO.INP","r",stdin);
    freopen("XAUFIBO.OUT","w+",stdout);
    int N,M,L;
    while(cin>>N>>M>>L){
    string F[10005];
    F[1] = 'b';
    F[2] = 'a';
    for(int i=3;i<=N;i++){
        F[i] = F[i-1]+F[i-2];
    }
        F[N] = ' '+F[N];
        if(M>F[N].size()) cout<<0<<' '<<"[0]";
        else{
            if(M+L>F[N].size()) cout<<F[N].size()-M<<' ';
            else cout<<(M+L) - M<<' ';
            cout<<"[";
            if(M+L>F[N].size()){
                for(int i=M;i<=F[N].size()-1;i++){
                    cout<<F[N][i];
                }
            }
            else{
                for(int i=M;i<=M+L-1;i++){
                    cout<<F[N][i];
                }
            }
            cout<<"]";
        }
        cout<<endl;
   }
}
