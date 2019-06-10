#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>

#define MAX 1002
using namespace std;
bool matrix[MAX][MAX];
class NODE
{
  public:
    int in;
    int out;
    char color;
    queue<int> next;
    NODE()
    {
        in = 0;
        out = 0;
        color = 'g';
    }
};
NODE node[MAX];
bool visited[MAX];
vector<int> cycle;

void tryDfs(int vis)
{
    if (node[vis].color == 'r')
    {
        if(cycle.at(cycle.size()-4) == vis)
        {
            cout << cycle[1] << " " << cycle[2] << " " << cycle[3] << endl;
            exit(0);
        }
        else 
        {
           // node[vis].color = 'b';
            cycle.pop_back();
        }
    }
    else if (node[vis].color == 'g')
    {
		node[vis].color = 'r';
        while (!node[vis].next.empty())
        {
            cycle.push_back(node[vis].next.front());
            tryDfs(node[vis].next.front());
            node[vis].next.pop();
        }
        node[vis].color = 'b';
    }
    else
        return;
}
void solve()
{
    int n, x;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        visited[i] = 0;
        for (int j = 1; j <= n; j++)
        {
            cin >> matrix[i][j];
            if (matrix[i][j])
            {
                node[i].out++;
                node[j].in++;
                node[i].next.push(j);
            }
            node[j].color = (node[j].in == 0 || node[j].out == 0) ? 'b' : 'g';
            node[i].color = (node[i].in == 0 || node[i].out == 0) ? 'b' : 'g';
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (node[i].color != 'b')
        {
			cycle.push_back(i);
			tryDfs(i);
            cycle.clear();
        }
    }
    cout << "-1 -1 -1\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}
