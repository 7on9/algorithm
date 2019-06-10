#include <iostream>
#include <algorithm>


using namespace std;
void solve()
{
    int n;     
    cin >> n;
    int *A,stack=0,*Buff;
    A = new int[n+1];
    Buff = new int[n+1];
    for (int i = 0;i < n ; i++)
    {
        cin >> A[i];
        if(i == 0) Buff[0] = i;
        Buff[i] += A[i];
        if(A[i]).
    }
    A[n] = 0;
    int money[n] ;
    for (int i = 1; i <= n; i++)
    {
        if(A[i] > A[i-1]) continue;
        else
        {
        }
    }
    cout << money << endl;
}
int main()
{
    int T;
    cin >> T;
    while (T)
    {
        solve();
        T--;
    }
    return 0;
}
