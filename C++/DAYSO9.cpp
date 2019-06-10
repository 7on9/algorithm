#include <iostream>
using namespace std;
int A[83];
int rev(int x)
{
    int s = 0;
    while (x)
    {
        s = s*10+(x%10);
        x /= 10;
    }
    return s+2;
}

int main()
{
    int n = 1;
    for (int i = 1; i <= 82; i++)
    {
        A[i] = n;
        n = rev(n);
    }
    long long a;
    cin >> a;
    if(a <=82) cout << A[a] << endl;
    else
    {
        while (a > 82)
        {
            a = a%82 + a/82;
        }
        cout  << A[a] << endl;
    }
    return 0;
}
