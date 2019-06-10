#include <iostream>
#include <algorithm>
#define divided 1000000000
using namespace std;
long check[1005];
int main()
{
    int n,*A;
    cin >> n;
    A = new int [n+3];
    for (int i = 1; i <= n ; i++)
        cin >> A[i];
    A[n+1] = 0;
    check[0] = 1;
    if (A[1] == 1 || A[1] == 0) check[1] = 1;
    else check[1] = 0;
    for (int i = 2; i <= n+1; i++)
    {
        if(A[i] == 0)
            for (int j = max(0, i-3); j < i; j++)
                if(j == i - 3 && A[j] == 1) continue;
                else check[i] = (check[i]+check[j])%divided;
        else if(A[i] == 1)
            check[i] = check[i-1];
        else check[i] = 0;
    }
    cout << check[n+1] % divided<< endl;
    return 0;
}
