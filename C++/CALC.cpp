#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
void solve()
{
    int n,b;
    cin >> n >> b;
    if(n/b == 1) cout << n%b << endl;
    else
    {
        int maxn = 0;
        int x = n%b-b;
        int y = n/b;
        for(int i = y ;i >= 1; i--)
        {
            x+=b;
            maxn = max(i*x,maxn);
        }
        cout << maxn <<endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    for (; T >0; T--) {
        solve();
    }
    return 0;
}
