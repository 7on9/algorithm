#include <iostream>
#include <stdio.h>
using namespace std;
long long a, temp, b, t, d;
void bin(long long &x)
{   
    if(x >= b) return;
    if((x << 1) < b)
    {
        x<<=1;
        bin(x);
    }
    else
    {
        d++;
        bin(++x);
    }
}
void solve()
{
    d = 0;
    cin >> a >> b;
    temp = a;
    bin(temp);
    cout  << d << endl;

}
int main()
{   
    cin >> t;
    while(t--)
    {
        solve();   
    }
    return 0;
}
