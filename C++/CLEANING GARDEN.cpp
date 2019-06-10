#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long int64;
vector <int> left1, right1;
int n, k;
long long distances = 0;
int oo = 2000000001;

void input()
{

    cin >> n >> k;
    for(int i = 1, temp; i <= n; i++)
    {
        cin >> temp;
        if(temp<0)
            left1.push_back(temp);
        else
            right1.push_back(temp);
    }
    sort(left1.begin(), left1.end(), greater<int>());
    sort(right1.begin(), right1.end());
}

int solve1()
{
    if(right1.size()>=k)
    return right1[k-1];
    else
    return oo;
}

int solve2()
{
    if(left1.size()>=k)
    return -left1[k-1];
    else
    return oo;
}

int solve3()
{
	int res=oo;
	int maxrange=min(k-2,int(left1.size()-1));
	for(int i=0;i<=maxrange;++i)
	{
		if(right1.size() >= k-i-1)
			res=min(res, -left1[i]*2+right1[k-i-2]);
	}
	
	maxrange=min(k-2,int(right1.size()-1));
	for(int i=0;i<=maxrange;++i)
	{
		if(left1.size() >= k-i-1)
			res=min(res, -left1[k-i-2]+right1[i]*2);
	}
	return res;
}

void solve()
{
	int res=oo;
	if(n==k)
	{
		if(left1.size()==0)
			res=right1.back();
		else
			if(right1.size()==0)
				res=-left1.back();
		else
		{
			int leftback=-left1.back();
			int rightback=right1.back();
			res=min(2*leftback+rightback,2*rightback+leftback);
		}
	}
	else
	{
		int res1=solve1();
		int res2=solve2();
		int res3=solve3();
		res=min(res1,res2);
		res=min(res,res3);
	}
    cout << res << endl;
}

int main()
{
    input();
    solve();
    return 0;
}
