#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

bool cmp(const iii &a, const iii &b)
{
	return a.second.second < b.second.second;
}
struct cmpMaxCost{
	bool operator() (const iii &a, const iii &b)
	{
//		if(a.second.first == b.second.first)
//			return a.second.second < b.second.second;
		return a.second.first < b.second.first;
	}
};
int n;
vector<iii> machine;
priority_queue <iii, vector<iii>, cmpMaxCost> maxCostMachine;
void prepare()
{
	cin >> n;
	machine.resize(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> machine[i].second.first;
	for (int i = 1; i <= n; i++)
	{
	    machine[i].first = i;
		cin >> machine[i].second.second;
	}
	sort(machine.begin(), machine.end(), cmp);
}
void solve()
{
	unsigned long long times = 0, fail = 0;
	vector<bool> res(n+1);
	for(int i = 1; i <= n; i++)
		res[i] = true ;
	for(int i = 1; i <= n; i++)
	{
		maxCostMachine.push(make_pair(i ,machine[i].second));
		times += machine[i].second.first;
		//res[machine[i].first] = true;
		if(times > machine[i].second.second)
		{
			res[maxCostMachine.top().first] = false;
			fail++;
			times -= maxCostMachine.top().second.first;
			maxCostMachine.pop();
		}
	}
	cout << fail << endl;
	for(int i = 1; i <= n; i++)
		if(res[i]) cout << machine[i].first << " ";
	for(int i = 1; i <= n; i++)
		if(!res[i]) cout << machine[i].first << " ";
}
int main()
{
	prepare();
	solve();
	return 0;
}
//lưu lại số máy
//sort tăng dần theo hạn hoàn thành
//heap sort theo giảm dần cost
//lấy từng cặp đã sort push heap xét đến khi lố tg thì trừ + pop ra heap.top
//in ra -> end

