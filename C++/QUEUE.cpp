#include <iostream>
#include <set>
#include <vector>
using namespace std;
//long check[1000000001];
long minn = -1000000000;
long searchMin(long *A,long n)
{
    long pos = 0;
    minn = *A;
    for(long i = 0;i < n;i++)
    {
        if(A[i] < minn)
        {
            minn = A[i];
            pos = i;
        } 
    }
    return pos;
}
void swap(long &a,long &b)
{
    long c = a;
    a = b;
    b= c;
}
int main()
{
    ios_base::sync_with_stdio(0);
    long n;
    cin >> n;
    long *A;
    A = new long[n+1];
    //multiset<long> B;
    for (long i = 0; i < n; i++)
    {
        cin >> A[i];
        //B.insert(A[i]);
        minn = min(A[i], minn);
    }
    for (long i = 1; i < n; i++)
    {
        long j = searchMin(A+i, n-i);
        if(A[j+i] < A[i-1])
        {
            cout << i << " " << j+i+1<< endl;
            swap(A[i-1], A[j+i]);
        }
    }
    return 0;
}
