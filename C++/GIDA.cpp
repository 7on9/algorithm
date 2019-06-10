//giao đấu xem đội B ăn đội A bnh người
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n,A[100006],B[100006];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < n; i++)
        cin >> B[i];
    sort(A, A+n);
    sort(B, B+n);
    int j ,i,d=0;
    i=j=n-1;
    do
    {
        //if(A[j] == 0) i--;
        if (j < 0) break;
        if(B[i] >A[j])
        {
            d++;
            i--;
        }
        j--;
    } while (i >=0 && j >= 0);
    cout << d << endl;
    return 0;
}
