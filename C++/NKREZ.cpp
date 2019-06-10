#include <iostream>
using namespace std;

int main()
{
    long n,sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int p ,k;
        cin >> p >> k;
        sum  +=  k - p;
   }
    cout << 24 * (sum /24 +1) - sum;
    return 0;
}
