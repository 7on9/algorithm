
#include <stdio.h>
#include <stdlib.h>
#define maxnmk 50000 //So phan tu toi da trong mang

int m,n,k,a[maxnmk+1],b[maxnmk+1],heap[maxnmk+1],nheap=0;

//Cap nhat mot gia tri vao heap
void update(int value)
{
    int child=++nheap,parent;
    while (child>=1)
    {
        parent=child/2;
        if (parent==0 || heap[parent]>=value) break;
        heap[child]=heap[parent];
        child=parent;
    }
    heap[child]=value;
}

//Lay mot phan tu ra khoi heap
void pop()
{
    int value=heap[nheap--], parent=1, child;
    while (parent<=nheap)
    {
        child=parent*2;
        if (child<nheap && heap[child+1]>heap[child]) child++;
        if (child>nheap || heap[child]<=value) break;
        heap[parent]=heap[child];
        parent=child;
    }
    heap[parent]=value;
}

//Xuat ket qua bang de quy
void print()
{
    if (nheap==0) return;
    int value=heap[1];
    pop();
    print();
    printf("%d\n",value);
}

int compare(const void *a, const void *b)
{
    return (*(int *)a>*(int *)b);
}
int main()
{
    //Doc dau vao
    scanf("%d%d%d",&m,&n,&k);
    for (int i=0;i<m;i++) scanf("%d",a+i);
    for (int i=0;i<n;i++) scanf("%d",b+i);
    //Sap xep hai mang tang dan
    qsort(a,m,sizeof(int),compare);
    qsort(b,n,sizeof(int),compare);
    //Duyet va cap nhat heap, xuat ket qua
    for (int i=0;i<m;i++)
        for (int j=0;j<n;j++)
        if (heap[1]>a[i]+b[j] || nheap<k)
        {
            if (nheap==k) pop();
            update(a[i]+b[j]);
        }
        else break;

    print();
    return 0;
}