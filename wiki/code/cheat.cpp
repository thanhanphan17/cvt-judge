#include<bits/stdc++.h>
using namespace std;

int  n,a[100100],s[100100],Max,top;

int main()
{
    freopen("Cheat.inp","r",stdin);
     freopen("Cheat.out","w+",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++)
        if (a[i] < Max) {
            if (a[i] != s[top]) {
                printf("YES");
                return 0;
            }
            top--;
        }
        else {
            for (int j=Max+1;j<a[i];j++) s[++top] = j;
            Max = a[i];
        }
    printf("NO");
    return 0;
}
