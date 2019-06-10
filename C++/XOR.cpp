#include<bits/stdc++.h>
using namespace std;
void Process(long long x,long long y)
{
	long long d=x%y;
	long long res1,res2;
	res1=x-d;
	res1=(x xor res1);
	res2=x+y-d;
	res2=(x xor res2);
	cout<<min(res1,res2)<<"\n";
}
int t;
int main()
{
	cin>>t;
	for(int i=1;i<=t;i++){
		long long a,n;
		cin>>a>>n;
		Process(a,n);
	}
	return 0;
}
