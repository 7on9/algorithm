#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int Bin[10005];
int size[10005];
int root(int x)
{
    if(Bin[x]!=x)
    {
        Bin[x] = root(Bin[x]);
        size[x]=1;
    }
    return Bin[x];
}
void connect(int x,int y)
{
    int rootx = root(x);
    int rooty = root(y);
    if(size[rootx] < size[rooty])
    {
        Bin[rootx] = Bin[rooty];
        size[rooty] += size[rootx];
    }
    else
    {
        Bin[rooty] = Bin[rootx];
        size[rootx] += size[rooty];
    }
}
bool isConnect(int x,int y)
{
    if(root(x) == root(y)) return true;
    return false;
}
int main()
{
    ios::sync_with_stdio(0);
    int n,x,y,z;
    scanf("%d",&n);
    for (int i = 0; i <= 10000; i++)
    {
        Bin[i] = i;
        size[i] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        if(z == 1)
        {
            connect(x, y);
        }
        else printf("%d\n", isConnect(x, y));
    }
    return 0;
}
