#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int a,int b)
{
    return (a > b);
}
int main()
{
    int *cow;
    int n,lost = 0,milk = 0;
    cin >> n;
    cow = new int [n];
    for (int i = 0; i < n; i++)
        cin >> cow[i];
    sort(cow, cow + n, cmp);
    for (int i = 0; i < n; i++)
    {
        cow[i] -= lost;
        if(cow[i] <= 0)
        {
            cout << milk << endl;
            return 0;
        }
        milk += cow[i];
        lost ++;
    }
    cout << milk << endl;
    return 0;
}
