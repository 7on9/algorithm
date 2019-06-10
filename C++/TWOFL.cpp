#include <iostream>
#include <vector>
#define MAXSIZE 2005
using namespace std;
int n,m,N;
int cha[MAXSIZE], rank[MAXSIZE];
int garden[MAXSIZE][MAXSIZE];
void init()
{
    for (int i = 0; i < N; i++)
    {
        cha[i] = i;
        rank[i] = 0;
    }
}

int find(int u)
{
    if (cha[u] != u)
        cha[u] = find(cha[u]);
    return cha[u];
}

void join(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    if (rank[u] == rank[v]) rank[u]++;
    if (rank[u] < rank[v]) cha[u] = v;
    else cha[v] = u;
}
void getdata()
{
    cin  >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            cin >> garden[i][j];
            cha[i][j] = garden[i][j];
            rank[i] = 0;
        }
}
int main()
{
    
    return 0;
}