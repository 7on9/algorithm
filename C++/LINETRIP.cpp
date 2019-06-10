#include <bits/stdc++.h>
using namespace std;
int nMax = -99999, nMin = 99999, n, x, step = 0;

void accepted()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        nMin = x < nMin ? x : nMin;
        nMax = x > nMax ? x : nMax;
    }    
    if(nMax < 0){
        nMax = 0;
    }
    if(nMin > 0)
        nMin = 0;
    else
        nMin *= -1;
    step = nMin * 2 + nMax * 2;
    cout << step;
}
int main()
{
    accepted();
    return 0;
}