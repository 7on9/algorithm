#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
int main()
{
    int q,n;
    cin >> q;
    int Result[q];
    for (int i = 0; i < q; i++)
    {
        cin >> n;
        int A;
        //int check[10005] = {};
       // memset(check, 1, sizeof(check));
        //check[0]++;
        cin >> A;
        int max = A;
        for (int j = 1; j < n; j++)
        {
            cin >> A;
            if(A>max) max = A;
        }
        Result[i] = n - max;
    }
    for (int i = 0; i < q; i++) {
        cout << Result[i] << endl;
    }
    return 0;
}
