#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n,m,A[100006],B[100006];
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < m; i++)
        cin >> B[i];
    sort(A, A+n);
    sort(B, B+m);
    int j ,i,d=0;
    i=n-1;
    j=m-1;
    do
    {
        //if(A[j] == 0) i--;
        if (j < 0) break;
        if(A[i] >B[j])
        {
            d++;
            i--;
        }
        j--;
    } while (i >=0 && j >= 0);
    cout << d << endl;
    return 0;
}
