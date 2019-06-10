//#include <bits/stdc++.h>
#include <iostream>
using namespace std;
bool solve()
{
    int n,m;
    cin >> n >> m;
    int A[101] = {};
    for(int i = 0;i < m;i++)
    {
        int a,b;
        cin >> a >> b;
        A[a]++;
        A[b]++;
        if(A[a] > 1 || A[b] >1) return false;
        else n-=2;
    }
    if(n%2 == 1) return false;
    return true;
}

int main()
{
    ios_base :: sync_with_stdio(0);
    int t;
    cin >> t;
    for(;t > 0;t--)
        if(solve()) cout << "yes" << endl;
        else cout << "no" << endl;
    return 0;
}
