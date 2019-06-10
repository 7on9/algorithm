//Đi đến trạm nào thì hết xăng
#include <iostream>
using namespace std;
int main()
{
    int n,x,a;
    cin >> n >> x;
    for (int i = 1; i < n; i++)
    {
        cin >> a;
        x -= a;
        if (x <= 0 )
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
