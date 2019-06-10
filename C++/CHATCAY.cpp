//https://www.hackerrank.com/contests/free-contest/challenges/chat-cay/problem
#include <iostream>
#include <vector>
#define ll long long
#define MAX 10 //6705
ll sMap[MAX][MAX];
using namespace std;
vector <int> arr;
vector <ll> sArr;
int n, k;
trong k cây phía trc chọn 1 cây ko chặt 
void input()
{
    cin >> n >> k;
    arr.resize(n + 1);
    sArr.resize(n + 1);
    arr[0] = sArr[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        sArr[i] = arr[i-1] + arr[i];
    }
}
void solve()
{
	for(int i = 1; i <= n;i++)
	{
		for(int j = 0; (j <= k-1) && (i - j >= 0); j++)
		{
			sMap[i][i - j] = sArr[i] - sArr[i-j-1];
		}
			
	}
//	cout << res << endl;
}
int main()
{
	input();
	solve();
    return 0;
}

