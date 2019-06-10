#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long d,B[1000005];
int main()
{
    int n,t;
    int *A;
    cin >> n >> t;
    A = new int[n+1];
    for (int i = 1; i <= n; i++)
    {
        cin >> B[i];
        A[i] = A[i-1] +B[i];
    }
    for (int i = 0;i <= n; i++)
    {
        int j = upper_bound(A+i+1, A+n+1, A[i]+t) - A - 1;
        d+=(j-i);
    }
    cout << d << endl;
    return 0;
}
