#include <iostream>
#include <list>
using namespace std;

int main()
{
    list <int> disc;
    int n,m;
    cin >> n >> m ;
    for(int i = 1;i <= n;i++)
        disc.push_back(i);
    for(int i = 0;i < m;i++)
    {
        cin >> n;
        disc.remove(n);
        disc.push_front(n);
        cout << disc.back() << " ";
    }
    return 0;
}