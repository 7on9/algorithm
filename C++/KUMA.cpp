#include <iostream>
using namespace std;
int main()
{
    int n, m ;
    float t;
    double cost = 0;
    cin >> m >> n >> t;
    t /= 1000000;
    do
    {
        // if(n == m) cout << m*t*100 << endl;
        if(n < m)
        {
            cost += n*t;
            n = 0;
        }
        else
        {
            cost += m*t;
            n-=(m+1);
        }
    }while (n > 0);
    if (cost < 1)
        cout << cost*1000000 <<endl;
    else cout << long(cost)*1000000 <<endl;
   // cout << cost*t*100 << endl
    return 0;
}
