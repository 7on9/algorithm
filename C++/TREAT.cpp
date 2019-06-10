#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
//include <bits/stdc++.h>
#define MAX 100002
using namespace std;

vector<int> candy(MAX);
vector<int> Next(MAX);
vector<int> cycle(MAX);
void tryDfs(int vis, int &c)
{
	stack<int> stk;
	stk.push(vis);
	cycle[vis] = ++c;
	while (true)
	{
		int next = Next[vis];
		if (cycle[next] == 0)
		{
			stk.push(next);
			cycle[next] = ++c;
		}
		else
		{
			int col = candy[next] != 0 ? candy[next] + 1 : cycle[vis] - cycle[next] + 1;
			bool back = candy[next] != 0;
			for (; !stk.empty(); stk.pop())
			{
				candy[stk.top()] = col;
				back = stk.top() == next ? true : back;
				if (back)
					col++;
			}
			break;
		}
		vis = next;
	}
}
void solve()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		candy[i] = 0;
		cin >> Next[i];
		Next[i]--;
	}
	int cycle_i = 0;
	for (int i = 0; i < n; i++)
		if (cycle[i] == 0)
			tryDfs(i, cycle_i);
	for (int i = 0; i < n; i++)
		printf("%d\n", candy[i]);
}
int main()
{
	ios_base::sync_with_stdio(0);
	solve();
	return 0;
}
