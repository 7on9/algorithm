#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 1000
void NhapSoLuongPhanTu(int &n)
{
    do
    {
        printf("Nhap so phan tu mang 0 < N <= %d : ",MAX);
        scanf("%d",&n);
        if(n <= 0 || n > MAX)
            printf("Can nhap n trong khoang tu 0 -> %d hay nhap lai!\n",MAX);
    }while (n <= 0 || n > MAX);
}
void Coppy(int A[],int B[],int n)
{
    for(int i = 0;i < n; i++)
        B[i] = A[i];
}
int posMin(int A[],int left,int right)
{
    int pos = left;
    for(int i = left;i < right;i++)
        if(A[pos] > A[i]) pos = i;
    return pos;
}
int NgauNhien(int a,int b)
{
    if(a >= b) return 0;
    return (rand()%(b-a+1)+a);
}
void NgauNhienChuoi(char S[],int n)
{
    for(int i = 0;i < n;i++)
        S[i] = char(NgauNhien(97,122));
}
void NgauNhienFloat(float S[],int n)
{
    for(int i = 0;i < n;i++)
        S[i] = 1.0*NgauNhien(0,MAX)/NgauNhien(1,MAX);
}
void NgauNhienAm(int S[],int n)
{
    for(int i = 0;i < n;i++)
        S[i] = NgauNhien(0,MAX)*-1;
}
void NhapMang(int A[],int n)
{
    for(int i = 0;i < n; i++)
    {
        //printf("A[%d] = ", i);
        //scanf("%d",&A[i]);
        A[i] = NgauNhien(0,MAX);
    }
}
void XuatMang(int A[],int n)
{
    for(int i = 0;i < n; i++)
        printf("\t%5d", A[i]);
    printf("\n");
}
void XuatMangThuc(float A[],int n)
{
    for(int i = 0;i < n; i++)
        printf("\t%5.2f", A[i]);
    printf("\n");
}
void Nhapx(int &x)
{
    printf("Nhap x can tim : ");
    scanf("%d",&x);
}
//Sort
void Swap(int &a,int &b)
{
    int c = a;
    a = b;
    b = c;
}
void QuickSort(int A[],int left,int right)
{
    int a_mid = A[(right + left)/2];
    int i = left,j = right;
    do
    {
        while (A[i] < a_mid) i++; //Tim phan tu ben trai ma >= A[mid]
        while (A[j] > a_mid) j--;
        if(i <= j)
        {
            Swap(A[i],A[j]);
            i++;
            j--;
        }
    }while (i < j);
    if(left < j) QuickSort(A,left,j); // Van con phan tu ben trai
    if(right > i) QuickSort(A,i,right);
}

void BubbleSort(int A[],int n)
{
    for(int i = 0;i < n;i++)
        for(int j = n-1;j > i;j--)
            if(A[j]<A[j-1]) Swap(A[j],A[j-1]);
}
void SelectionSort(int A[],int n)
{
    for(int i = 0;i < n-1;i++)
        Swap(A[i],A[posMin(A,i+1,n)]);
}
void ShellSort(int A[],int n,int h[],int k)
{
    int step,pos,len,x;
    for(step = 0;step < k;step++)
    {
        len = h[step];
        for(int i = len;i < n;i++)
        {
            x = A[i];
            pos = i - len;
            while((x < A[pos])&&(pos >= 0))
            {
                A[pos+len] = A[pos];
                pos = pos - len;
            }
            A[pos+len] = x;
        }
    }
}
void MergeSort(int A[],int n)
{
    int k,low1,low2,up1,up2,size,i,j;
    int dstam[MAX];
    size = 1;
    while(size < n)
    {
        low1 = 0;
        k = 0;
        while(low1+size < n)
        {
            low2 = low1+size;
            up1 = low2-1;
            up2 = (low2+size-1 < n)? (low2+size-1):(n-1);
            /*if(low2+size-1 < n)
                up2 = low2+size-1;
                else up2 = n-1;
            */
            for( i = low1, j = low2;i <= up1 && j <= up2;k++)
                if(A[i] <= A[j]) dstam[k] = A[i++];
                else dstam[k] = A[j++];
            for(;i <= up1;k++) dstam[k] = A[i++];
            for(;j <= up2;k++) dstam[k] = A[j++];
            low1 = up2+1;
        }
        for(int i = low1;k < n;i++) dstam[k++]=A[i];
        for(int i = 0;i < n;i++) A[i] = dstam[i];
        size*=2;
    }
}
void RadixSort(long A[],int n)
{
    int d,digit,num;
    int h = 10;
    long B[10][MAX];
    int Len[10];
    for(int d = 0;d < MAX;d++)
    {
        for(int i = 0;i < n;i++)
            Len[i] = 0;
        for(int i = 0;i < n;i++)
        {
            digit = (A[i]%h)/(h/10);
            B[digit][Len[digit]++] = A[i];
        }
        num = 0;
        for(int i = 0;i < 10;i++)
            for(int j = 0;j < Len[i];j++)
                A[num++] = B[i][j];
        h *= 10;
    }
}
void InsertionSort(int A[],int n)
{
    int pos , x;
    for (int i = 1;i < n;i++)
    {
        x = A[i];   // giu vi tri A[i]
        pos = i-1; //xet tu vi tri trc
        while (pos >= 0 && A[pos] > x) //tim vi tri thich hop de chen x
        {
            A[pos+1] = A[pos]; //don phan tu ra sau
            pos--; // doi post
        }
        A[pos+1] = x; //
    }
}
void InterchangeSort(int A[],int n)
{
    for(int i = 0;i < n-1;i++)
        for(int j = i+1;j < n;j++)
            if(A[i] > A[j]) Swap(A[i],A[j]);
}
void InterchangeSortinverse(int A[],int n)
{
    for(int i = 0;i < n-1;i++)
        for(int j = i+1;j < n;j++)
            if(A[i] < A[j]) Swap(A[i],A[j]);
}
//Tim kiem
int TimTuyenTinh(int A[],int n,int x)
{
    for(int i = 0 ;i < n; i++)
        if(A[i] == x) return i;
    return -1;
}
int TimNhiPhan(int A[],int left,int right,int x)
{
    if(left > right) return -1; //Khong tim thay
    int mid = (left + right)/2;
    if(A[mid] == x) return mid; //Tim thay
    if(A[mid] > x) return TimNhiPhan(A,left,mid-1,x); // Tim mang ben trai
    if(A[mid] < x) return TimNhiPhan(A,mid+1,right,x); // Tim mang ben phai
    return 0;
}
int TimNhiPhaninverse(int A[],int left,int right,int x)
{
    if(left > right) return -1; //Khong tim thay
    int mid = (left + right)/2;
    if(A[mid] == x) return mid; //Tim thay
    if(A[mid] < x) return TimNhiPhaninverse(A,left,mid-1,x); // Tim mang ben trai
    if(A[mid] > x) return TimNhiPhaninverse(A,mid+1,right,x); // Tim mang ben phai
    return 0;
}
int Menu()
{
    int chose;
    printf("\tXIN MOI CHON TAC VU :\n");
    printf("\t0 : Thoat\n");
    printf("\t1 : Tim kiem tuyen tinh\n");
    printf("\t2 : Tim kiem nhi phan\n");
    printf("\t3 : Bubble Sort \n");
    printf("\t4 : Selection Sort \n");
    printf("\t5 : Insertion Sort \n");
    printf("\t6 : Quick Sort \n");
    printf("\t7 : Merge Sort \n");
    printf("\t8 : Shell Sort \n");
    printf("\t9 : Interchange Sort \n");
    printf("\t10 : Radix Sort \n");
    printf("\t11 : Random va in ra mot chuoi so thuc \n");
    printf("\t12 : Random chuoi ki tu \n");
    printf("\t13 : Tim kiem nhi phan chuoi giam dan\n");
    printf("\t14 : Random va in ra mot chuoi so nguyen am \n");
    printf("Ban chon -> ");
    scanf("%d",&chose);
    return chose;
}
int main()
{
    srand((int)time(NULL));
    int A[MAX], n, x, pos, chose, Acopy[MAX];
    NhapSoLuongPhanTu(n);
    NhapMang(A,n);
//    int h[]={5,3,1};
//    ShellSort(A, n, h, 3);
    printf("Mang A : ");
    XuatMang(A,n);
    /*
     pos = TimTuyenTinh(A,n,x);
     if(pos != -1)
     printf("Tim thay %d o vi tri thu %d\n",x,pos);
     else printf("Khong tim thay !\n");
     */
    do
    {
        chose = Menu();
        //chuyen mang A vao Acopy
        Coppy(A,Acopy,n);
        switch(chose)
        {
            case 0 : printf("Ban vua chon thoat chuong trinh\n"); break;
            case 1 : printf("Ban vua chon tim kiem tuyen tinh \n");
            {
                Nhapx(x);//Nhap x de tim
                pos = TimTuyenTinh(Acopy,n,x);
                if(pos != -1)
                    printf("Tim thay %d o vi tri thu %d\n",x,pos);
                else printf("Khong tim thay !\n");
                break;
            }
            case 2 : printf("Ban vua chon tim kiem nhi phan \n");
            {
                QuickSort(Acopy,0,n-1); //Sap xep
                printf("Day da sap xep : \n");
                printf("Mang A : ");
                XuatMang(Acopy,n);//Xuat mang da sap xep
                Nhapx(x);//Nhap x de tim
                pos = TimNhiPhan(Acopy,0,n-1,x);
                if(pos != -1)
                    printf("Tim thay %d o vi tri thu %d\n",x,pos);
                else printf("Khong tim thay %d !\n",x);
                break;
            }
            case 3 : printf("Ban vua chon Bubble sort !\n");
            {
                BubbleSort(Acopy,n);
                printf("Mang A sap xep theo Bubble Sort : ");
                XuatMang(Acopy,n);
                break;
            }
            case 4 : printf("Ban vua chon Selection sort !\n");
            {
                SelectionSort(Acopy,n);
                printf("Mang A sap xep theo Selection Sort : ");
                XuatMang(Acopy,n);
                break;
            }
            case 5 : printf("Ban vua chon Insertion sort !\n");
            {
                InsertionSort(Acopy,n);
                printf("Mang A sap xep theo Insertion Sort : ");
                XuatMang(Acopy,n);
                break;
            }
            case 6 : printf("Ban vua chon Quick sort !\n");
            {
                QuickSort(Acopy,0,n-1);
                printf("Mang A sap xep theo Quick Sort : ");
                XuatMang(Acopy,n);
                break;
            }
            case 7 : printf("Ban vua chon Merge sort !\n");
            {
                MergeSort(Acopy,n);
                printf("Mang A sap xep theo Merge Sort : ");
                XuatMang(Acopy,n);
                break;
            }
            case 8 : printf("Ban vua chon Shell sort !\n");
            {
                QuickSort(Acopy,0,n-1);
                printf("Mang A sap xep theo Quick Sort : ");
                XuatMang(Acopy,n);
                break;
            }
            case 9 : printf("Ban vua chon Interchange sort !\n");
            {
                InterchangeSort(Acopy,n);
                printf("Mang A sap xep theo Interchange Sort : ");
                XuatMang(Acopy,n);
                break;
            }
            case 10 : 
            case 11 : printf("Mot mang so thuc ngau nhien : \n");
            {
                printf("Nhap chieu dai mang \n");
                int len;
                NhapSoLuongPhanTu(len);
                float S[len];
                NgauNhienFloat(S,len);
                printf("Mang thuc ngau nhien : ");
                XuatMangThuc(S,len);
                break;
            }

            case 12 : printf("Mot chuoi ki tu ngau nhien : \n");
            {
                printf("Nhap chieu dai chuoi ki tu\n");
                int len;
                NhapSoLuongPhanTu(len);
                char S[len];
                NgauNhienChuoi(S,len);
                printf("Chuoi ngau nhien : ");
                puts(S);
                break;
            }
            case 13 : printf("Ban vua chon tim kiem nhi phan chuoi giam dan \n");
            {
                InterchangeSortinverse(Acopy,n); //Sap xep
                printf("Day da sap xep : \n");
                printf("Mang A : ");
                XuatMang(Acopy,n);//Xuat mang da sap xep
                Nhapx(x);//Nhap x de tim
                pos = TimNhiPhaninverse(Acopy,0,n-1,x);
                if(pos != -1)
                    printf("Tim thay %d o vi tri thu %d\n",x,pos);
                else printf("Khong tim thay %d !\n",x);
                break;
            }
            case 14 : printf("Mot mang so so nguyen am ngau nhien : \n");
            {
                printf("Nhap chieu dai mang \n");
                int len;
                NhapSoLuongPhanTu(len);
                int S[len];
                NgauNhienAm(S,len);
                printf("Mang nguyen am ngau nhien : ");
                XuatMang(S,len);
                break;
            }
            default : printf("Lenh vua nhap cua ban khong co trong MENU !\n");
        }
        printf("Nhap 0 de thoat hoac 1 so bat ki de tiep tuc \n");
        printf("Ban chon -> ");
        scanf("%d",&chose);
        if(chose == 0) printf("Ban vua chon thoat chuong trinh !\n");
    }while(chose != 0);
    return 0;
}













