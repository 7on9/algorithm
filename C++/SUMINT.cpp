#include <iostream>
#include <math.h>
using namespace std;
long res,B[1000001][2];
int main()
{
    ios::sync_with_stdio(0);
    int n;
    long *A;
    cin >> n;
    A = new long[n+1];
    *A = 0;
    for (int i = 1;i <= (n/2)+1; i++)
    {
        A[i] = A[i-1] + i;
        if(i < sqrt(n)) continue;
        for (int j = i-1; j >= 1; j--)
        {
            if(A[i] - A[j-1] > n) break;
            if (A[i] - A[j-1] == n)
            {
                res++;
                B[res][0] = j;
                B[res][1] = i;
                break;
            }
        }
        //if (A[i] > n) break;
    }
    cout << res << endl;
    for (int i = res; i >= 1; i--)
    {
        cout << B[i][0] << " " << B[i][1] << endl;
    }
    delete A;
    return 0;
}
