#include <iostream>
using namespace std;
string  solve()
{
	int n, a, single = 0 ;
	cin >> n;
	int xorSum = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> a;
		if(a == 1) single++;
		xorSum ^= a;
	}
	return ((n % 2 == 0 && single == n) || (xorSum != 0 && single != n)) ? "First" : "Second";
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		cout << solve() << endl;
	}
	return 0;
}
