#include <iostream>
#include <math.h>
using namespace std;
//long num(long long L,long long R)
//{
//    return long (sqrtl(R)) - long(sqrtl(L-1));
//}
int main()
{
    int T;
    cin >> T;
    while (T)
    {
        long long L,R;
        cin >> L >> R;
        cout << /*num(L,R)*/long (sqrtl(R)) - long(sqrtl(L-1)) << endl;
        T--;
    }
    return 0;
}
