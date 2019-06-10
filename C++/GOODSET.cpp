#include <iostream>
using namespace std;
long A[110],a=2;
void solve()
{
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)
        cout << A[i] <<' ';
    cout << endl;
}
int main()
{
    int t;
    cin >>t;
    A[1] = 1;
    A[2] = 2;
    A[3]= 4;
    for(int i = 4;i<=100;i++)
        A[i] = A[i-1]+3;
    while (t)
    {
        t--;
        solve();
    }
    return 0;
}
