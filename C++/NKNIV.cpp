#include <iostream>
using namespace std;
//BIT trong bai nay bi dao nguoc 2 thao tac update va get
int F[60010], res = 0;
void get(int x)
{
    for (; x <= 60010; x += x & -x)
        res += F[x];
}
void update(int x)
{
    for (; x; x -= x & -x)
        F[x]++;
}
int main()
{
    int n, x;
    cin >> n;
    for(int j= 0;j < n;j++)
    {
        cin >> x;
        update(x);
        get(x+1);
    }
    cout << res << endl;
    return 0;
}
