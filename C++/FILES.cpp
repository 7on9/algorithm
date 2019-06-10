#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct StructPoint
{
    float x;
    float y;
};
typedef StructPoint Point;
void create(Point *A,int n)
{
    for (int i = 1; i <= n;i++)
    {
        A[i].x = rand()%51 - rand()%51;
        A[i].y = rand()%51 - rand()%51;
    }
}
void print(Point *A,int n,char *file_name)
{
    FILE *f;
    f = fopen(file_name, "wb");
    for (int i = 1; i <= n; i++)
        fwrite(A+i, sizeof(Point), 1, f);
    fclose(f);
}
void readOUT(char *file_name)
{
    FILE *f;
    f = fopen(file_name, "rt");
    Point A;
    while (fread(&A, sizeof(Point), 1, f) == 1)
    {
        printf("(%.2f , %.2f) ",A.x, A.y);
    }
    fclose(f);
}
//Lưu tọa độ dương
void positive(char *filein,char *fileout)
{
    Point A;
    FILE *fin,*fout;
    fin = fopen(filein, "rb");
    fout = fopen(fileout, "wb");
    while (fread(&A, sizeof(Point), 1, fin) == 1)
    {
        if(A.x > 0 && A.y > 0) fwrite(&A, sizeof(Point), 1, fout);
    }
    fclose(fin);
    fclose(fout);
}

int main()
{
    
    int n;
    Point *A;
    srand((unsigned int)time(NULL));
    printf("Nhập số phần tử của mảng : ");
    scanf("%d",&n);
    A =(Point *)malloc(n);
    create(A, n);
    print(A, n,"mang.inp");
    positive("mang.inp", "sort.out");
    readOUT("sort.out");
    return 0;
}
