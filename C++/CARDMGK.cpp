#include <iostream>
#include <vector>
using namespace std;
void solve()
{
    int n, numSub = 0;
    bool inc = false;
    cin >> n;
    vector<int> arr(n + 1);
    arr[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        inc = (arr[i] >= arr[i-1]) ? true : false;
        if(!inc) 
        {
            numSub++;        }
    }
	switch (numSub)
	{
		case 0:
			cout << "YES" << endl;
			return;
		case 1:
			if(arr[n] <= arr[1])
				cout << "YES" << endl;
			else cout<< "NO" << endl;
			return;
	}
	cout<< "NO" << endl;
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



