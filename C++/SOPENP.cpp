#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

set <string> sinA; 
vector <int> Num;
int n, l, u, a = 0;
string x;
void solve()
{
    for(int i = 0;i <= n; i++ )
        for(int j = i;j <= n;j++ )
        {
            bool kt = true;
            int d = 0;
            for(int k = i + 1;k <= j;k++ )
            {
                for(int z = i;z < k;z++ )
                    if(Num[k] != Num[z]) d++;
            }
            if(d >= l && d <= u) a++;
        }
}
void getData()
{
    cin >> n >> l >> u;
    for(int i = 0;i < n; i++)
        cin >> x;
}
int main()
{   
    int *A;
    getData();
    solve();
    //f(l == 1) d+=Num.size() ;
    cout << d << endl;
    return 0;
}
