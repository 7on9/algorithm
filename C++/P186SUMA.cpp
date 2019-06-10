#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
bool flag;
long long A[100005];
void prepare()
{
    cin >> n >> m;
	for(int i = 0; i < n; i++)
    {
        cin >> A[i];
        A[i] %= m;
        if(i > 0) A[i] += A[i-1];
        if(A[i]%m == 0) flag = true;
    }
}
void solve()
{
    if(flag) 
    {
        cout << "Yes" << endl;
        return;
    }
    for(int i = 0; i < n-2; i++)
    {
        for(int j = i + 1; j <= n-1;j ++)
            if((A[j] - A[i])%m==0)
            {
                cout << "Yes" << endl;
                return;
            }
    }
	cout << "No" << endl;
}
int main()
{
	ios::sync_with_stdio(0);
    prepare();
	solve();
    return 0;
}
