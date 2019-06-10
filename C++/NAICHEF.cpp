#include <iostream>
#include <stdio.h>
using namespace std;
long long a,n,b,t;
void solve()
{
    cin >> a >> b;
    for(int i = 0;i < n; i++)
    {
        cin >> temp;
        if(temp == a) na++;
        if(temp == b) nb++;
    }
    float x = (na*nb* 1.0)/(n*n);
    printf("%.10lf\n",x);
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
