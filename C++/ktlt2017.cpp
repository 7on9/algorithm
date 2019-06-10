#include <stdio.h>
#include <stdlib.h>
void docfile(char *file_name,int A[])
{
    FILE *f;
    f = fopen(file_name, "r");
    if(f!=NULL)
    {
        for(int i = 0;i < 10;i++)
            fscanf(f, "%d ", &A[i]);
    }
    fclose(f);
}
void ghifile(char *file_name,int A[])
{
    FILE *f ;
    f = fopen(file_name,"wt");
    for(int i = 0;i < 10; i++)
        fprintf(f , "%d ", A[i]);
    fclose(f);
}
int main()
{
    int A[] = {1,2,3,4,5,6,7,8,9,10};
    int B[11];
    ghifile("INP.txt", A); //ghi dữ liệu từ mảng A vào file INP
    docfile("INP.txt", B); // doc dữ liệu từ file INP
    ghifile("OUT.txt", B); // ghi dữ liệu vào file OUT
    for (int i = 0; i < 10; i++) // ghi ra màn hình
    {
        printf("%d ",B[i]);
    }
    return 0;
}
