#include <iostream>
#include <algorithm>
#define maxsize 1000001
using namespace std;

int check[maxsize];
int checkA[maxsize];
int checkB[maxsize];
int maxgcd = 0; //UCLN
void mark1(int a)
{
    for(int i = 1;i*i <= a;i++)
        if(a%i == 0)    
        {
            check[i] = 1;
            check[a/i] = 1;
        }
}
void mark2(int b)
{
    for(int i = 1;i*i <= b;i++)
        if(b%i == 0)    
        {
            if(check[i] == 1) maxgcd = max(maxgcd,i);
            if(check[b/i] == 1) maxgcd = max(maxgcd,b/i);
        }
}
int main()
{
    ios_base :: sync_with_stdio(0);
    int *A,*B,n;
    int maxA = 0,maxB = 0;
    cin >> n;
    A = new int [n];
    B = new int [n];
    for(int i = 0;i < n;i++)
    {
        cin >> A[i];
        mark1(A[i]);
        checkA[A[i]]++;
        maxA = max(maxA,A[i]);
    }
    for(int i = 0;i < n;i++)  
    {
        cin >> B[i];
        mark2(B[i]);
        checkB[B[i]]++;
        maxB = max(maxB,B[i]);
    }
    // sort(A,A+n);
    // sort(B,B+n);
    int sum = 0;
    if(maxgcd != 1) 
    {
        for(int j = 1;j*maxgcd <= maxA;j++)
            if(checkA[j*maxgcd] != 0) sum = j*maxgcd;
        int sum2=0;
        for(int j = 1;j*maxgcd <= maxB;j++)
            if(checkB[j*maxgcd] != 0) sum2 = j*maxgcd;
        sum+=sum2;
    }
    else
    {
        sum = maxA+maxB;
    }
    cout << sum << endl;
    free(A);
    free(B);
    return 0;
}

