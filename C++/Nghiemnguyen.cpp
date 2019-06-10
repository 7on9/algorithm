#include <iostream>

using namespace std;

int main()
{
    int a,b;
    int n,i;
    cin >> n;
    for(i = 1;i <= n;i++)
    {
        cin >> a >> b;
        cout << ((b-1)/3)-((a-2)/3) << endl;
    }
    return 0;
}
//9x+2=y^2+y
//9x+2=y(y+1)
//1
