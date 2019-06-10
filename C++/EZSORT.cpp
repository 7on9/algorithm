#include <iostream>
using namespace std;
int main()
{
    long n,A[300005],max;
    cin >> n;
    for (long i = 0; i < n ; i++)
    {
        cin >> A[i];
        if(i == 0) max = A[i];
        if(A[i] > max) max = A[i];
    }
    
    return 0;
}
