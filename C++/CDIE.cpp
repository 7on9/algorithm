#include <iostream>
#include <algorithm>
using namespace std;
int A[60],need,n,total,m;
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    sort(A, A+n);
    total = 1;
    for (int i = n-1; i >= 0; i--)
    {
        if (total >= m)
        {
            cout << need << endl;
            return 0;
        }
        total += A[i]-1;
        need++;
    }
    cout << "-1" << endl;
    return 0;
}
