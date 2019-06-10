#include <iostream>
#include <algorithm>
using namespace std;
void solve()
{
    int n,m1=0,m=0,m2=0,d=0;
    cin >> n;
    int check[100001]={};
    for (int j = 0; j < n; j++)
    {
        char c;
        cin >> c;
        if(c == '*')
        {
            m1++;
            check[j]++;
        }
    }
    int flag = 0;
    m+=m1;
    for (int j = 0; j < n; j++)
    {
        char c;
        cin >> c;
        if(c == '*')
        {
            m2++;
            if(check[j] == 0) m++;
            else
            {
                if (flag==0)
                {
                    d++;
                    flag++;
                }
            }
        }
    }
    d+= m-1;
    d=max(d, 0);
    cout << d << endl;
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
