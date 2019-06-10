#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve()
{
    int n, x, maxNum = -1;
    long long tt = 0;
    cin >> n >> x;
    vector <int> arr(n+1);
    for(int i = 1;i <= n;i++)
    {
        cin >> arr[i];
        maxNum = max(maxNum, arr[i]);
    }
    for(int i = 1;i <= n;i++)
    {
        if((maxNum - arr[i]) % x != 0)
        {
            cout << -1 << endl;
            exit(0);
        }   else tt += (maxNum - arr[i]) / x;
    }
    cout << tt << endl;
}
int main()
{
    solve();
    return 0;
}
