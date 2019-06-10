#include <iostream>
#include <algorithm>
#define maxsize 1000001
using namespace std;
int checkA[maxsize];//dem so lan xuat hien cac so trong mang a
int checkB[maxsize];//dem so lan xuat hien cac so trong mang b
int inA[maxsize];   //boi lon nhat cua i trong mang A
int inB[maxsize];   //boi lon nhat cua i trong mang B
void markA()
{
    for(int i = 2;i <= maxsize;i++)
        for(int j = i;j <= maxsize;j+=i)
            if(checkA[j])
                inA[i]=j;
}
void markB()
{
    for(int i = 2;i <= maxsize;i++)
        for(int j = i;j <= maxsize;j+=i)
            if(checkB[j])
                inB[i]=j;
}
int main()
{
    ios_base :: sync_with_stdio(0);
    int *A,*B,n;
    int maxA = 0,maxB = 0;//phan tu lon nhat cua mang A - B
    cin >> n;
    A = new int [n];
    B = new int [n];
    for(int i = 0;i < n;i++)
    {
        cin >> A[i];
        checkA[A[i]]++;
        maxA = max(maxA,A[i]);
    }
    markA();
    inA[1] = maxA; 
    for(int i = 0;i < n;i++)
    {
        cin >> B[i];
        checkB[B[i]]++;
        maxB = max(maxB,B[i]);
    }
    markB();
    inB[1] = maxB;
    maxA = max(maxA,maxB); //phan tu lon nhat cua ca 2 day
    for(int i = 1;i <= maxA;i++)
        if(inA[i] && inB[i]) //tai i co boi o ca A va B
            n = i;
    cout << inA[n]+inB[n] << endl;
    free(A);
    free(B);
    return 0;
}

