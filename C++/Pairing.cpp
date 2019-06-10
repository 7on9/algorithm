#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a,b,c,d,dem=0;
	cin>>a>>b>>c>>d;
	if (b>d)
	{
		dem=b-d;
		if ((a%2==0&&c%2!=0)&&(a%2!=0&&c%2!=0)) dem=dem+1;
	}
	if (b<d)
		dem=d-b;
		if ((c%2==0&&a%2!=0)&&(a%2!=0&&c%2!=0)) dem=dem+1;
	if (b==d) dem=c%2+a%2;
	cout<<dem;
	return 0;
}
