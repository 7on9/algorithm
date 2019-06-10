#include <iostream>
#include <algorithm>
using namespace std;
int A[50001*2];
void solve()
{
    int n ;
    cin >> n;
    //int A[n*2+2];
    for (int i = 0; i < n*2 ; i++)
        cin >> A[i];
    sort(A, A+n*2);
    cout << A[n+(n/2)] << endl;
    for (int i = 0; i < n ; i++)
    {
        if(i != 0) cout << " ";
        cout << A[i] << " " << A[n*2-i-1];
    }
    cout << endl;
}
int main()
{
    int q;
    cin>> q;
    for (int i = 1; i <= q; i++)
        solve();
    return 0;
}
