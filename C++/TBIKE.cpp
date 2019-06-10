#include <iostream>
#include <algorithm>
using namespace std;
int A[2001],res;
int main()
{
    int n;
    cin >> n;
    for (int i = 0;i < n; i++)
        cin >> A[i];
    sort(A, A+n);
    for (int i = 0; i < n; i++)
    {
        if(A[i] > 0)
        {
            int k = 0,j2 = 0;
            for (int j = i + 1; j < n;  j++)
                if (A[i] < A[j] && k == 0)
                {
                    k = A[j] - A[i];
                    j2 = j;
                    break;
                }
            int c = 1;
            if(j2 != 0)
            {
                for (int j = j2; j < n;  j++)
                    {
                        if(A[i]+k*c == A[j])
                        {
                            A[j] = 0;
                            c++;
                        }
                    }
            }
            res++;
        }
        A[i] = 0;
    }
    cout << res << endl;
    return 0;
}
//1 2 2 3 5 5 9 11 17
//1 2 3
//2 5
//5 9
//11 17
