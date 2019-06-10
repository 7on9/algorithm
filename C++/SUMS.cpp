#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int A[100],S[100],S2[100],n,s=-1,Sum,dem;
bool check[100];
int binsearch(int A[],int left,int right,int x)
{
    if(left > right) return -1;
    int mid = (left + right) / 2;
    if (A[mid] == x) return mid;
    if (A[mid] < x) return binsearch(A, mid + 1, right, x);
    return binsearch(A, left, mid - 1, x);
}
void Pepare()
{
    sort(A,A + (n/2+1));
    for(int i = 0;i < n/2;i++)
    {
        if(check[A[i]]) continue;
        s++;
        S[s] = A[i];
        check[A[i]] = true;
        for(int j = i+1;j < n/2; j++)
        {
            if(check[A[i]+A[j]]) continue;
            s++;
            S[s] = A[i] + A[j];
            check[A[i]+A[j]] = true;
        }
    }
    s++;
    S[s] = 0;
}
void Pepare2()
{
    for(int i = n/2;i < n;i++)
    {
        if(check[A[i]]) continue;
        s++;
        S[s] = A[i];
        check[A[i]] = true;
        for(int j = i+1;j < n; j++)
        {
            if(check[A[i]+A[j]]) continue;
            s++;
            S[s] = A[i] + A[j];
            check[A[i]+A[j]] = true;
        }
    }
}
void Submit()
{
    sort(S,S+s+1);
    int max = 0;
    for(int i = 0; i <= s;i++)
    {
        //if(S[i] == Sum/2) continue;
        int pos = binsearch(S, 0 , s-1, Sum - S[i]);
        if (pos != -1 && Sum-S[i] >= max)
        {
            dem++;
            if(max == 0)  max = S[i+1];
            else
            max = S[i];
        }
    }
}
int main()
{
    cin >> n >> Sum;
    for (int i = 0 ; i < n ; i++)
        cin >> A[i];
    Pepare();
    Pepare2();
    Submit();
    cout << dem;
    cout << endl;
    return 0;
}
