#include <bits/stdc++.h>

using namespace std;

int a[2500][2500],b[3000],n,i,j,h,dem,k,x,m;
void ChuyenMang(int A[][2500], int m,int n,int B[],int &p)
{
    p =m*n;    //p là số phần tử của mảng B
    for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
    B[i*n + j] = A[i][j];
}
/********************************/

//SẮP XẾP MÃNG 1 CHIỀU
void SapXep1Chieu(int A[], int n)
{

    for (int i = 0; i < n - 1; i++)
    for (int j = i + 1; j < n; j++)
    if (A[i] > A[j])
            {
            int t = A[i];
            A[i] = A[j];
            A[j] = t;
            }

}
/********************************/
//SẮP XẾP ZIXZAC NGANG
void SapXepZicZac(int A[][2500], int m, int n)
{


    int B[2500];
    int p;
    ChuyenMang(A,m,n,B,p);
    SapXep1Chieu(B,p);
    int vt = 0;
    int i, j;
    for (i = 0; i < m; i++)
    {
        if (i%2 == 0)
            for (j = 0; j < n; j++)
            {
            A[i][j] = B[vt];
            vt++;
            }
        else
            for (j = n - 1; j >= 0; j--)
            {
            A[i][j] = B[vt];
            vt++;
            }
    }
}

/********************************/
//SẮP XẾP XOẮN ỐC
void SapXepXoanOc(int A[][2500], int m, int n)
{
    int B[2500];
    int p;
    ChuyenMang(A,m,n,B,p);
    SapXep1Chieu(B,p);
    int tren = 0, duoi = m - 1, trai = 0, phai = n - 1;
    int i, vt = 0;
    do
    {
        for (i = trai; i <= phai && vt < p; i++)
            A[tren][i] = B[vt++];
        tren++;
        for (i = tren; i <= duoi && vt < p; i++)
            A[i][phai] = B[vt++];
        phai--;
        for (i = phai; i >= trai && vt < p; i--)
            A[duoi][i] = B[vt++];
        duoi--;
        for (i = duoi; i >= tren && vt < p; i--)
            A[i][trai] = B[vt++];
        trai++;
    } while (tren <= duoi && trai <= phai);
}

/********************************/
//SẮP XẾP ZICZAC XÉO
void SapXepZicZacXeo(int A[][2500], int m, int n)
{
    int B[2500];
    int p;
    ChuyenMang(A,m,n,B,p);
    SapXep1Chieu(B,p);
    int vt = 0;
    int trai,phai;
    trai = 1;
    phai = 1;
    int i = 0, j = 0;
    A[i][j] = B[vt++];
    do
    {
        if (j == n - 1)
            i++;
        else
            j++;
        A[i][j] = B[vt++];

        while (i < m - 1 && j > 0)
        {
            i++;
            j--;
            A[i][j] = B[vt++];

        }
        if (i == m - 1)
            j++;
        else
            i++;
        A[i][j] = B[vt++];

        while (i > 0 && j < n - 1)
        {
            i--;
            j++;
            A[i][j] = B[vt++];
        }

    } while (i < m - 1 || j < n - 1);
}

void NhapMaTran(int a[][2500], int &m, int &n)
{
    cin>>n;
    m=n;
    h=0;
    for (i=0;i<n;i++)
    for (j=0;j<m;j++)
    { cin>>a[i][j];
      b[h++]=a[i][j];
    }
     sort(b,b+h);

}
void XuatMaTran(int a[][2500], int dong, int cot)
{
for(int i = 0; i < dong; i++)
{
for(int j = 0; j < cot; j++)
{cout<< a[i][j] <<' ';
}
cout<< endl;// cout<< "\n";
}
}

int ganle(int a[3000],int i,int j,int n)
{
    return (a[n*(i-1)+j-1]);
}
int ganchan(int a[3000],int i,int j,int n)
{
    return (a[n-j+1+n*(i-1)-1]);
}
int main()
{
    freopen("BAI11.INP","r",stdin);
    freopen("BAI11.OUT","w+",stdout);

  NhapMaTran(a,m,n);
  SapXepZicZac(a,m,n);
  XuatMaTran(a,m,n);
  for (j=n;j>=1;j--)
    {
        for (i=n;i>=1;i--)
            if ((i%2)==0) cout<<ganchan(b,i,j,n)<<" ";
            else cout<<ganle(b,i,j,n)<<" ";
        cout<<"\n";
    }
    SapXepXoanOc(a,n,m);
    XuatMaTran(a,m,n);
    SapXepZicZacXeo(a,m,n);
    XuatMaTran(a,m,n);
}
