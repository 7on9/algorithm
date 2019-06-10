#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n,*Mang;
    int maxn=0,num = 0;
    cin >> n;
    Mang = new int [n];
    for (int i = 0; i < n; i++)
    {
        cin >> Mang[i];
        if (i > 1)
        {
            if(Mang[i] == (Mang[i-1]+Mang[i-2]))
            {
                if(num == 0) num += 3;
                else num++;
            }
            else    num = 0;
            maxn = max(maxn,num);

        }
    }
    if(maxn == 0) cout << "-1" << endl;
    else cout << maxn << endl;
    return 0;
}
