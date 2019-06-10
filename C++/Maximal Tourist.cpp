#include <iostream>
#include <algorithm>
using namespace std;
int maxn = 0;
class Bin
{
public:
    Bin()
    {
        cap = this;
        value = 0;
    }
    Bin *root()
    {
        Bin *res=this;
        while(res->cap != res)
            res = res->cap;
        return res;
    }
    Bin *cap;
    int value;
};

void getBin(Bin *x,Bin *y)
{
    x=x->root();
    y=y->root();
    if(x<y)
    {
        x->value++;
        y->root()->cap=x;
        maxn = max(maxn, x->value);
    }
    else
    {
        y->value++;
        x->root()->cap=y;
        maxn=max(maxn, y->value);
    }
}
bool isConnect(Bin *x,Bin *y)
{
    if(x->root() == y->root())
        return true;
    return false;
}
int main()
{
    ios::sync_with_stdio(0);
    int n,x,y,m;
    cin >> n>>m;
    Bin bin[10001];
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y ;
        getBin(&bin[x],&bin[y]);
    }
    cout << maxn << endl;
    return 0;
}
