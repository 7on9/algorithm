//https://www.codechef.com/JULY18B/problems/MGCSET
#include <iostream>
#include <vector>
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector <int> a(n+2), b(n+2);
    bool flag = false;
    int count = 0;
    long long kq = 0;
    for(int i = 1;i <= n; i++)
    {
        cin >> a[i];
        if(!flag && a[i]%m == 0)
        {
            flag = true;
            count++;
        } else 
            if(flag && a[i]%m != 0)
            {
                flag = false;
                kq += (count % 2 == 0) ? ((count + 1) * (count/2)) : ((count+1) * (count/2) + (count/2) + 1);
                count = 0;
            }   else
                    if(flag && a[i]%m == 0)
                        count++;
    }
    if(count != 0)
        kq += (count % 2 == 0) ? ((count + 1) * (count/2)) : ((count+1) * (count/2) + (count/2) + 1);
    cout << kq << endl;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}
