//chồng gạch
#include <iostream>
#include <algorithm>
using namespace std;
int Gach[101];
int main()
{
    int limit;
    int n, high = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> Gach[i];
    sort(Gach, Gach + n + 1);
    if (Gach[n] >= n)
    {
        limit = 1;
    }
    else
        limit = n - Gach[n];
    while (n > limit)
    {
        n--;
        high++;
        if (Gach[n] < Gach[n + 1] && n - Gach[n] > limit)
            limit = n - Gach[n];
    }
    cout << high << endl;
    return 0;
}
