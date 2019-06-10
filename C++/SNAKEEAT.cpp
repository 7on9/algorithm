//rắn ăn nhau
#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
//#define min(a,b) (((a)<(b))?(a):(b))

typedef long long int64;

int asc(const void *a, const void *b)
{
    int A=*((int*)a);
    int B=*((int*)b);
    if(A<B)
        return -1;
    if(A>B)
        return 1;
    return 0;
}

typedef struct
{
    int number,k;
}Quest;

int asck(const void *a, const void *b)
{
    Quest &A=*((Quest*)a);
    Quest &B=*((Quest*)b);
    if(A.k<B.k)
        return -1;
    if(A.k>B.k)
        return 1;
    return 0;
}

typedef struct
{
    int l;//number of snack were eaten
    int r;
} Window;

int main()
{
    //freopen("D:\\input.txt","rt",stdin);
    int t,n,q;
    int *L=new int [100005];
    int64 *sum=new int64[100005];
    Quest *quests=new Quest[100005];
    int *ans=new int [100005];
    scanf("%d",&t);
    while(t)
    {
        scanf("%d%d",&n,&q);
        for(int i=1;i<=n;++i)
            scanf("%d",&L[i]);
        L[0]=0;
        qsort(&L[1],n,sizeof(int),&asc);
        for(int i=1;i<=n;++i)
            sum[i]=sum[i-1]+L[i];
        for(int i=0;i<q;++i)
        {
            scanf("%d",&quests[i].k);
            quests[i].number=i;
        }
        qsort(quests,q,sizeof(Quest),&asck);
        Window w;
        w.l=0;
        w.r=0;
        for(int i=0;i<q;++i)
        {
            while((w.r < n) && (L[w.r+1] < quests[i].k)) //find the first unsatisfy
                ++w.r;
            while((w.l < w.r) && (sum[w.r]-sum[w.l]+w.l < int64(w.r-w.l)*quests[i].k))
                ++w.l;
            ans[quests[i].number]=n-w.l;
        }
        for(int i=0;i<q;++i)
            printf("%d\n",ans[i]);
        --t;
    }
    //getch();
    return 0;
} 
