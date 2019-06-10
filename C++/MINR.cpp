#include <iostream>
using namespace std;
int A[100005];
int Min(int left,int right)
{
    int min = A[left];
    for(int i = left;i <= right;i++)
        if(A[i] < min) min = A[i];
    return min;
}
void Perpare()
{
    
}
int main()
{
    int m,n;
    cin >> n >> m;
    for(int i = 1;i <= n ;i++)
        cin >> A[i];
    
    return 0;
}
