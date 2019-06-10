
//  YoungerBrotherofTurtle.cpp

#include <stdio.h>
#include <stdlib.h>
//Ước chung lớn nhất
int UCLN(int a,int b)
{
    if(a*b)
        if(a>b) return UCLN(a%b, b);
        else return UCLN(a, b%a);
    return a+b;
}
//Giai thừa
long Giaithua(int n)
{
    if(n == 1 || n == 0) return 1;
    return Giaithua( n-1)*n;
}
void XuatLe(int A[],int n)
{
    if(n == 0) return; // -> điều kiện dừng
    XuatLe(A, n-1);
    if (A[n-1] % 2 != 0)
        printf("%d ",A[n-1]);
    // Margik
}
int Tong(int A[],int n)
{
    if (n == 1)
        return A[0];
    return Tong(A,n-1)+A[n-1];
}
int Tongbp(int n)
{
    if (n == 0) return 0;
    return Tongbp(n-1)+(n*n);
}
int Posc(int A[],int n,int a)
{
    if (n == 0) return -1;
    if (A[n-1] == a) return n-1;
    return Posc(A, n-1, a);
}
//}
//int Posd(int A[],int n,int a)
//{
//    if (n == 0)
//        return -1;
//    if (A[n-1] == a) return n-1;
//    return Posd(A, n-1, a);
//}

int Fibonaci(int n)
{
    if(n < 2)
        return 1;
    return Fibonaci(n-1)+Fibonaci(n-2);
}

int FindBinary(int A[],int left,int right,int x)
{
    if (left > right) return -1;
    int mid = (left+right) / 2;
    if (A[mid] == x) return mid;
    if(A[mid] < x) return FindBinary(A, mid+1, left, x);
    return FindBinary(A, left, mid+1, x);
}
int main()
{
    int n ,m ;
    printf("Nhập m : ");
    scanf("%d",&m);
    printf("Nhập n : ");
    scanf("%d",&n);
    printf("UCLN = %d\n",UCLN(abs(m),abs( n)));
    printf("%d! = %ld\n",m ,Giaithua(m));
    int A[] = {1,2,3,4,5,6,7,8,9,11,12,13,11,15};
    XuatLe(A, 14);
    printf("\n%d\n",Tong(A,14));
    printf("%d\n",Tongbp(3));
    printf("%d\n",Posc(A, 14, 11));
    printf("%d\n",Fibonaci(4));
    printf("%d\n",FindBinary(A, 0, 14, 3));
    return 0;
}
//minhthai.edu.vn
