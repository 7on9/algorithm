#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    int *A;
    long long *S;
    int n,p;
    cin >> n >> p;
    A = new int[n+2];
    S = new long long[n+2];
    S[0]  = 0;
    for(int i = 0;i < n;i++)
    {
        cin >> A[i];
        S[i+1] = S[i] + A[i];
    }
    for(int i = 0;i < n;i++)
        for(int i = 0;i < n;i++)
    cout << "-1" << endl;
    return 0;
}
