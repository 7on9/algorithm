//Số ông bà táo
#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
    int ot,bt,k;
    int n = 0;
    cin >> ot >> bt >> k;
    n = min((ot/2),bt);
    ot-=(n*2);
    bt-=n;
    k-=(ot+bt);
    if (k > 0) k+=(ot+bt);
    while (k > 0)
    {
        n--;
        ot+=2;
        bt++;
        k-=(ot+bt);
        if (k > 0) k+=(ot+bt);
    }
    cout << n << endl;
    return 0;
}
