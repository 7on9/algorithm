#include <bits/stdc++.h>
using namespace std;
int n, a, b, p, place;
long long x = 1;
void accepted()
{
    cin >> n >> a >> b;
    p = b - a + 1;
    if(n == 1)
        cout << p << endl;
    else{
        p = n - 2;
        cout << b*p - a*p + 1 << endl;
    }
}
int main()
{
    accepted();
    return 0;
}