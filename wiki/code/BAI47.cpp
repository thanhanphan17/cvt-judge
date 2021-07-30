// Ý tưởng là đưa hết ước của n vô mãng a, sau đó tính tổng các chữ số của các ước n đưa và mãng b
// Kiểm tra phần tử max trong mãng b nếu b[i] max thì xuất a[i];
// Số phần tử là số đếm ước
#include <iostream>
#include <stdio.h>

using namespace std;

int n,i,j,dem=0,a[100000],b[100000];

int Maxx(int a[], int n) // Max
{
	int Maxx = a[1];
	for(int i=1; i<=n; i++)
		if(a[i] > Maxx)
			Maxx = a[i];
	return Maxx;
}

int TCS(int x) // Tổng chữ số
{
 int tong=0,m;
    while(x>0)
    {
    m=x%10;
    tong=tong+m;
    x=x/10;
    }
 return tong;
}

int main()
{
    freopen("BAI47.INP","r",stdin);
    freopen("BAI47.OUT","w+",stdout);
    cin>>n;
    for(i=1;i<=n;i++)
    {
            if(n%i==0)
            {
                // Mãng a có số phần tử là đếm.
               dem++;
               a[dem]=i;
            }
    }
    // Đưa vô 1 mãng phụ b, mãng b là mãng chứa tổng các chữ số của các ước.
    for(i=1;i<=dem;i++)
        {
            b[i]=TCS(a[i]); // Mãng này chứa tổng chữ số
        }
// For này tìm max bên mãng b tức là max của tổng các chữ số của phần tử.
    for(i=1;i<=dem;i++)
    {
        if(b[i]==Maxx(b,dem))
       {
           cout<<a[i];
           break; // Chỉ xuất 1 số
       }
    }
}
