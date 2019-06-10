#include <iostream>
#include <algorithm>
#define ll long long
#define MAX 100005
#define oo 1000000000000000000
using namespace std;

typedef pair<ll, ll> item;
int n;
ll T = oo / 2;
item arr[MAX];
ll maxArr[MAX];

void input()
{
	cin >> n;
	//int arr[n+1], brr[n+1];
	for (int i = 1; i <= n; i++)
		cin >> arr[i].first;
	for (int i = 1; i <= n; i++)
		cin >> arr[i].second;
}
bool isGood(ll cost)
{
	int left, right, mid, pos;
	for(int i = 1; i < n; i++)
	{
		pos = n + 1;
		left = i + 1;
		right = n;
		while(left <= right)
		{
			mid = (left + right) >> 1; 
			if(arr[i].first * arr[mid].first >= cost)
			{
				right = mid - 1;
				pos = mid;
			}
			else
				left = mid + 1;
		}
		if(pos > n)
			continue;
		if(arr[i].second * maxArr[pos] >= cost)
			return true;
	}
	return false;
}
void solve()
{
	sort(arr, arr + n + 1);
	maxArr[n] = arr[n].second;
	for (int i = n - 1; i >= 1; i--)
		maxArr[i] = max(maxArr[i + 1], arr[i].second);
	ll start = 1;
	ll end = oo;
	ll mid;
	while(start <= end)
	{
		mid = (start + end) >> 1;
		if(isGood(mid))
		{
			T = mid;
			start = mid + 1;
		}
		else
			end = mid - 1;
	}
	cout << T << endl;
}
int main()
{
	input();
	solve();
	return 0;
}
