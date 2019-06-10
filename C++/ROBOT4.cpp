#include <iostream>
#include <queue>
#include <vector>
#define MAX 21
using namespace std;
int m,n;
bool A[MAX][MAX],Map[MAX][MAX][5],found;
//0 up 1 right 2 down 3 left
class Blo
{
public:
    int r,c;
};
Blo flag,temp;
vector <Blo> go;

void reset()
{
    go.clear();
	for (long i = 1; i <= 20; i++)
	    for (long j = 1; j <= 20; j++)
	        for (long k = 0; k < 4; k++)
	            Map[i][j][k] = 0;
}

bool valid(int r, int c,int dir,int d)
{
    if(r < 1 || c < 1 || r > n || c > m || A[r][c] || Map[r][c][dir] || d > 2000 || found)
        return false;
    return true;
}

void getData(int &n,int &m)
{
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)
            cin >> A[i][j];
    cin >> flag.r >> flag.c;
}

void print()
{
    long step = go.size();
    cout << step << endl;
    for(int i = 0;i < step;i++)
        cout << go[i].r << " " << go[i].c << endl;
}

void dfs(int r,int c,int dir,int d)
{
    if(!valid(r, c, dir, d)) return;
    Map[r][c][dir] = 1;
    temp.r = r;
    temp.c = c;
    go.push_back(temp);
    if(r == flag.r && c == flag.c)
        {
            found = 1;
            print();
            return;
        }
    switch(dir)
    {
        case 0 : 
            dfs(r-1, c, dir, d+1);
            dfs(r, c-1, 3, d+1);
            break;
        case 1 : 
            dfs(r, c+1, dir, d+1);
            dfs(r-1, c, 0, d+1);
            break;
        case 2 : 
            dfs(r+1, c, dir, d+1);
            dfs(r, c+1, 1, d+1);
            break;
        case 3 :
            dfs(r, c-1, dir, d+1);
            dfs(r+1, c, 2, d+1);
            break;
    }
    go.pop_back();
}
int main()
{
    //freopen("data.inp","w",stdin);
    ios_base::sync_with_stdio(0);
    getData(n,m);
    //dir = 2
    Map[1][1][2] = 1;
    go.push_back({1, 1});
    dfs(2,1,2,0);
    if(!found)
        {
            reset();
            Map[1][1][1] = 1;
            go.push_back({1, 1});
            dfs(1,2,1,0);
            if(!found)
                cout << "0" << endl;
        }
    return 0;
