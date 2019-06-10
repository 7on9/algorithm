#include <iostream>
#include <algorithm>
using namespace std;
int room,have[100005],rent[100005];
int main()
{
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> rent[i];
    for (int i = 1; i <= n; i++)
    {
        cin >> have[i];
        have[i] += rent[i];
    }
    sort(rent+1, rent+n+1);
    sort(have+1, have+1+n);
    int j = 1;
    for (int i = 1; i <= n; i++)
    {
        if(rent[i] < have[j])
            room++;
        else j++;
    }
    cout << room << endl;
    return 0;
}
