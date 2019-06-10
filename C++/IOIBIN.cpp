#include <iostream>
#include <algorithm>
using namespace std;
class Bin
{
public:
    Bin()
    {
        cap = this;
    }
    Bin *root()
    {
        Bin *res=this;
        while(res->cap != res)
            res = res->cap;
        return res;
    }
    Bin *cap;
};

void getBin(Bin *x,Bin *y)
{
    x=x->root();
    y=y->root();
    if(x<y)
        y->root()->cap=x;
    else
        x->root()->cap=y;
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
    int n,x,y,z;
    cin >> n;
    Bin bin[10001];
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y >> z;
        if(z == 1)
        {
            getBin(&bin[x],&bin[y]);
        }
        else cout << isConnect(&bin[x],&bin[y]) << endl;
    }
    return 0;
}
