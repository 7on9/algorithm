//tìm UCLN và BCNN của n số
#include <iostream>
#include <stdlib.h>
using namespace std;

long long UCLN(long long a, long long b)
{
    if (a % b == 0)
        return b;
    return UCLN(b, a % b);
}
long long BCNN(long long a, long long b)
{
    return a * b / UCLN(a, b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    long long q, n;
    long long A[6];
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> n;
        long long B[n];
        if (n == 1)
        {
            cin >> A[i];
            continue;
        }
        for (int j = 0; j < n; j++)
        {
            cin >> B[j];
            if (j == 0)
                continue;
            A[i] = B[j] = BCNN(B[j], B[j - 1]);
        }
        //A[i] = BCNN(B, n[i]);
    }
    for (long long i = 0; i < q; i++)
    {
        cout << A[i] << endl;
    }
    return 0;
}
