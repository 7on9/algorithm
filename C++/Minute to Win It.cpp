//https://www.hackerrank.com/contests/w38/challenges/minute-to-win-it
#include <iostream>
#include <vector>
#include <map>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#define ll long long
using namespace std;
map <ll,ll> tank;
ll minuteToWinIt()
{
    ll n, k, x;
    ll pos = 0,S = 0;
    ll minute = 0;
    cin >> n >> k;
    vector <int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        S += a[i];
    }
    for(int i = 0; i < n; i++)
    {
        x = a[i] - ((i - 1)*k);
        pos = S-(n*x + (n-1)*k);
        tank[pos]++;
        minute = max(minute, tank[pos]);
    }
    return n - minute;
}
int main()
{
    cout << minuteToWinIt() << endl;
    return 0;
}
