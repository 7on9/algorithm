#include <iostream>
#include <algorithm>
using namespace std;
long A[1005],money,cost;
int main()
{
    int n,m;
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
        cin >> A[i];
    sort(A+1, A+n+1);
    for (int i = n; i >= 1; i--)
        if (A[i]*min((n-i+1),m) >= money)
        {
            money = A[i]*min((n-i+1),m);
            cost = A[i];
        }
    cout << cost <<  " "  << money <<endl;
    return 0;
}
