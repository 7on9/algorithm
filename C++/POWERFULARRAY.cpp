#include <iostream>
using namespace std;
//int check[10005];
int main()
{
    int n,q;
    int Q[10005][2];
    int A[10005],B[10005];
    cin >> n >> q;
    //A=new int (n+1);
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
        B[i]=A[i];
        A[i] +=A[i-1];
    }
    for (int i = 1; i <= q; i++)
    {
        cin >> Q[i][0] >> Q[i][1];
    }
    for (int i = 1; i <= q; i++)
        if(Q[i][0]==Q[i][1])
            cout << B[Q[i][1]] << endl;
        else
            if(Q[i][0]+1==Q[i][1])
                cout << (A[Q[i][1]] - A[Q[i][0]-1]) << endl;
            else cout << 2*(A[Q[i][1]] - A[Q[i][0]-1]) << endl;
    return 0;
}
