#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int n;
    cin >>n ;
    int *A;
    A = new int [n];
    for (int i = 0 ; i < n; i++)
        cin >>A[i];
    sort(A,A+n, cmp);
    for (int i = 0 ; i < n; i++)
        cout << A[i] <<" ";
    cout <<endl;
    return 0;
}
