#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

typedef long long ll;

ll cal(ll a, ll b)
{
    ll res = 10;
    for (ll i = b; i; i >>= 1)
    {
        if (i & 1)
            res = res * a % MOD;
        a = a * a % MOD;
    }
    return res;
}
void solve()
{
    ll n;
    cin >> n;
    if (n > 0)
    {
        cout << cal(2, n - 1) << endl;
    }
    else
    {
        cout << 0 << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
