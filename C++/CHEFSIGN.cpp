#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
void solve()
{
    string S;
    cin >> S;
    int len = S.size();
    int k = 0,maxn = 1;
    for (int i = 0; i < len; i++) {
        if(S[i] == '<')
        {
            k++;        }
        if(S[i] == '>')
        {
            k--;
        }
        maxn = max(abs(k)+1, maxn);
    }
    cout << maxn << endl;
}
int main()
{
    int T;
    cin >> T;
    for (; T >0; T--) {
        solve();
    }
    return 0;
}
