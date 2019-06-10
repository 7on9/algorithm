#include <stdio.h>
#include <stdlib.h>
#include <mm_malloc.h>
struct StructPhanSo
{
    int tu;
    int mau;
};
typedef StructPhanSo PhanSo;
void NhapPhanSo(PhanSo &ps)
{
    printf("Nhập tử : ");
    scanf("%d",&ps.tu);
    do
    {
        printf("Nhập mẫu : ");
        scanf("%d", &ps.mau);
        if(ps.mau == 0) printf("Mẫu phải khác không ! \n");
    } while (ps.mau ==0);
}
void NhapMang(PhanSo *ps,int &n)
{
    printf("Nhập số phần tử : ");
    scanf("%d",&n);
    for(int i = 0;i < n; i++)
    {
        printf("Nhập PS[%d] : \n",i+1);
        NhapPhanSo(*(ps+i));
    }
}
void XuatPhanSo(PhanSo ps)
{
    printf("%d / %d\n",ps.tu, ps.mau);
}
void XuatMang(PhanSo *ps,int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("PS[%d] = ",i+1);
        XuatPhanSo(*(ps+i));
    }
}
int UCLN(int a, int b)
{
    a = abs(a);
    b = abs(b);
    while (a*b)
    {
        if (a > b)
        {
            a %= b;
        }else b %= a;
    }
    return a+b;
}
PhanSo RutGon(PhanSo &A)
{
    A.tu /= UCLN(A.tu, A.mau);
    A.mau /= UCLN(A.tu, A.mau);
}
PhanSo Tong(PhanSo A,PhanSo B)
{
    PhanSo  kq;
    kq.tu = A.tu * B.mau + B.tu * A.mau;
    return kq;
}
PhanSo Tinh(PhanSo A,PhanSo B, PhanSo (*Ham)(PhanSo,PhanSo))
{
    PhanSo Kq = (*Ham)(A,B);
    return Kq;
}
int main()
{
    int n;
    PhanSo *ps;
    ps = (PhanSo *) malloc(1000);
    NhapMang(ps,n);
    XuatMang(ps, n);
}
