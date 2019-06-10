#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int A[101];
int dem;
int main()
{
    int a,b,c,d;
    cin >> a >> b;
    cin >> c >> d;
    dem = (b-a) + (d-c);
    int maxn =max(max(a,b),max(d,c));
    int minn =min(min(a,b),min(d,c));
    if(c < b && minn == a && maxn == d) dem -= abs(b-c);
    if(a < d && minn == c && maxn == b) dem -= abs(d-a);
    if(a >= c && b <= d || c >= a && d <= b) dem = maxn-minn;
    cout << dem << endl;
    return 0;
}
