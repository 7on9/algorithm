#include <iostream>
#include <map>
using namespace std;
int main()
{
	map<char,int> mx,my;
	int n,m,dem=0,k=0;
	string sx,sy;	
	cin>>n>>m;
	cin>>sx>>sy;	
	for(int i=0;i<n;i++)
		mx[sx[i]]++;
	for(int i=0;i<m;i++)
	{
		k++;
		my[sy[i]]++;
		if(k==n)
		{
			if(mx==my) dem++;
			my[sy[i-n+1]]--;
			if(my[sy[i-n+1]]==0) my.erase(sy[i-n+1]);
			k--;
		}
	}
	cout<<dem;
	return 0;
}
