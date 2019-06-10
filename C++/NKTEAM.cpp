#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 100005
#define INF 1000000002
class Pos
{
public:
    int contest1;
    int contest2;
    int contest3;
    bool operator < (Pos x)const
    {
        return contest1 < x.contest1;
    }
};
Pos PC[MAX_N];
int Res[MAX_N];
void update(int i, int value)
{
    for(;i <= MAX_N;i+=(i&-i))
        Res[i] = min(Res[i], value);
}
int get(int i)
{
    int bestPlayer = INF;
    for(;i;i-=(i&-i))
        bestPlayer = min(bestPlayer, Res[i]);
    return bestPlayer;
}
void doIt()
{
    int n, x, i;
    cin >> n;
    for(i = 1;i <= n;i++)
        Res[i] = INF;
    //pos x in contest1/2/3 = player i
    for(i = 1;i <= n;i++)
    {
        cin >> x;
        PC[x].contest1 = i;
    }
    for(i = 1;i <= n;i++)
    {
        cin >> x;
        PC[x].contest2 = i;
    }
    for(i = 1;i <= n;i++)
    {
        cin >> x;
        PC[x].contest3 = i;
    }
    sort(PC+1,PC+n+1);
    x = 0;
    for(i = 1;i <= n;i++)
    {
        if(get(PC[i].contest2)>PC[i].contest3)
            x++;
        update(PC[i].contest2, PC[i].contest3);
    }
    cout << x << endl;
}
int main()
{
    doIt();
    return 0;
}
