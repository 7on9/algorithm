//Tặng Hoa
#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int total = min(min((n+m)/3,n),m);
    if(n == 1 || m == 1) total = 1;
    cout << total << endl;
    while ((n >=1 && m > 1) || (n > 1 && m >= 1))
    {
        if (n < m && total > 0)
        {
            cout << "1 2" << endl;
            n--;
            m-=2;
        }
        else
        {
            cout << "2 1" << endl;
            n-=2;
            m--;
        }
    }
    return 0;
}
