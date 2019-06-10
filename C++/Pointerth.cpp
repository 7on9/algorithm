#include <stdio.h>
#include <stdlib.h>
void Nhap(int &a)
{
    scanf("%d",&a);
}
void Xuat(int a)
{
    printf("%d\n",a);
}
void NhapMang(int *A,int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("A[%d] = ",i);
        Nhap(*(A+i));
    }
}
void XuatMang(int *A,int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("A[%d] = ",i);
        Xuat(*(A+i));
    }
}
int TongMang(int *A,int n)
{
    int tong = 0;
    for (int i = 0; i < n; i++)
        tong += *(A+i);
    return tong;
}
void swap(int &a,int &b)
{
    a += b;
    b = a-b;
    a -= b;
}
void sort(int *A,int n)
{
    for (int i = 0 ; i < n-1; i++)
        for (int j = i+1; j < n; j++)
        {
            if(*(A+i) > *(A+j)) swap(*(A+i), *(A+j));
        }
}
int main()
{
    int *A,n;
    printf("Nhập số lượng phần tử : ");
    scanf("%d",&n);
    A = (int *) malloc(n);
    NhapMang(A, n);
    XuatMang(A, n);
    printf("Tổng mảng = %d\n",TongMang(A,n));
    sort(A, n);
    XuatMang(A, n);
    return 0;
    
}
