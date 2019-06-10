#include <iostream>
using namespace std;
char temp[5][5];
string res [10003];
void write()
{
    
}
void solve()
{
    int n, k;
    string s;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> s;
        for(int j = 0; j < n; j++)
            temp[i][j+1] = (s[j] == '.') ? '.' : '*';
    }
    for(int i = 1; i <= k; i++)
    {
        
    }
}
int main()
{
//    freopen("FRACTAL.INP", "rt", stdin);
//    freopen("FRACTAL.OUT", "wt", stdin);
    solve();
    long long  j = 3;
    for(int i = 1; i <= 5; i++)
        j *= 3;
        cout << j ;
    return 0;
}
