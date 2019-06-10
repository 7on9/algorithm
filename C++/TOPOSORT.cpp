#include <iostream>
#include <vector>
#include <deque>
#include <set>
#define FAIL "Sandro fails."

using namespace std;
int n, m;
vector <int> res;
vector <bool> visited;
vector < deque<int> > edge;
vector <int> indegree;
set <int> que;

void solve()
{
	cin >> n >> m;
	vector <bool> temp(n + 1, false);
	visited = temp;
	edge.resize(n+1);
	indegree.resize(n+1);
	int u, v;
	for(int i = 1; i <= m; i++)
	{
		cin >> u >> v;
		edge[u].push_back(v);
		indegree[v]++;
	}
	for(int i=1 ; i<=n ; i++)
		if(indegree[i] == 0)
		    que.insert(i);
	int count = 0;
	while (!que.empty())
	{
		int vertex = *que.begin();
		que.erase(que.begin());
		res.push_back(vertex);
		while(!edge[vertex].empty())
		{
			indegree[edge[vertex].front()]--;
			if (indegree[edge[vertex].front()] == 0)
				que.insert(edge[vertex].front());
			edge[vertex].pop_front();
		}
		count++;
	}

	if (count != n)
		cout << FAIL << endl;
	else
	{
		for (int i = 0; i < res.size(); i++)
			cout << res[i] << " ";
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	solve();
	return 0;
}
