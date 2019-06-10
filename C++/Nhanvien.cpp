#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define MAX 1000
typedef struct CongNhanVien
{
	int maso;
	char hoten[51];
	float luong;
}CNV;
//random fuction
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
float NgauNhienFloat()
{
    return 1.0*NgauNhien(0,MAX)/NgauNhien(1,MAX);
}
//file
void docfile(char *file_name,CNV A[],int n)
{
    FILE *f;
    f = fopen(file_name, "r");
    if(f!=NULL)
    {
        for(int i = 0;i < n;i++)
        {
            fscanf(f, "%d", &A[i].maso);
            fscanf(f, "%s", &A[i].hoten);
            fscanf(f, "%f", &A[i].luong);
        }
    }
    fclose(f);
}
void ghifile(char *file_name,CNV NV[],int n)
{
    FILE *f ;
    f = fopen(file_name,"wt");
	for(int i = 0;i < n; i++)
	{
        fprintf(f , "%d\n", NV[i].maso);
        fprintf(f , "%s\n", NV[i].hoten);
        fprintf(f , "%.2f\n", NV[i].luong);
	}
	fclose(f);
}
//random info 
void NgauNhienInfo(CNV NV[],int n)
{
	for(int i = 0;i < n;i++)
	{
		NV[i].maso = NgauNhien(0,MAX);
		NgauNhienChuoi(NV[i].hoten,50);
		NV[i].luong = NgauNhienFloat();
	}
}
//Nhap = tay
void NhapSoLuongNV(int &n)
{
	do
	{
		printf("Nhap so nhan vien < N <= %d : ",MAX);
		scanf("%d",&n);
		if(n <= 0 || n > MAX) 
			printf("Can nhap n trong khoang tu 0 -> %d hay nhap lai!\n",MAX);
	}while (n <= 0 || n > MAX);
}

void NhapMotNV(CNV &a)
{
	printf("Nhap ma so : ");
	scanf("%d",&a.maso);
	printf("Nhap ho ten : ");	
	fflush(stdin);
	gets(a.hoten);
	printf("Nhap luong : ");
	scanf("%f",&a.luong);
}
void XuatMotNV(CNV &a)
{
	printf("\tMa so : %d\n",a.maso);
	printf("\tHo ten : %s\n",a.hoten);	
	printf("\tLuong : %.2f\n",a.luong);
}
void NhapDanhSachNV(CNV A[],int n)
{
	for(int i = 0 ;i < n;i++)
	{
		printf("Nhap nhan vien %d :\n",i);
		NhapMotNV(A[i]);
	}
}
void XuatDanhSachNV(CNV A[],int n)
{
	for(int i = 0 ;i < n;i++)
	{
		printf("Nhan vien %d :\n",i);
		XuatMotNV(A[i]);
	}
}
int TimTuyenTinh(CNV A[],int n,char name[])
{
	for(int i = 0;i < n;i++)
		if(strcmp(name,A[i].hoten) == 0) return i;
	return -1;
}

int main()
{
    srand((int)time(NULL));
	int n;
	CNV A[MAX];
	char name[51];
	NhapSoLuongNV(n);
	//NgauNhienInfo(A,n);
	// NhapDanhSachNV(A,n);
    docfile("Wowo.inp",A,n);
	XuatDanhSachNV(A,n);
    //ghifile("Wowo.inp",A,n);
    
	printf("Nhap ho ten nhan vien de tim : ");
	fflush(stdin);
	gets(name);
	int pos = TimTuyenTinh(A,n,name);
	if(pos != -1) XuatMotNV(A[pos]);
	else printf("Khong tim thay nhan vien %s !\n ",name);
	return 0;
}
