#include <iostream>
#include <algorithm>

using namespace std;
void solve()
{
    int n;
    int  MAX = 0;
    cin >> n;
    int M[n];
    M[0] = 0;
    int *CP;
    CP = new int[n+1];
    CP[0] = 0;
    for(int i = 1;i <= n;i++)
    {
        cin >> CP[i];
        M[i] = M[i-1]+CP[i];
    }
    int d = 0;
    for(int i = 1;i < n;i++)
    {
        if(CP[i] <= CP[i+1]) d++;
        else
        {
            CP[i] = max(CP[i]*(i-1)-M[i-1],CP[i]*d-M[i-1]);
            d = 0;
            MAX = max(CP[i],CP[i] + MAX);
        }
    }
    cout << MAX << endl;
}
int main()
{
    int T;
    cin >> T;
    while(T)
    {
        solve();
        T--;
    }
    return 0;
}
