#include <iostream>
#include <algorithm>
#include <math.h>
#define MAX 10000001
using namespace std;
bool check[MAX];
class Num
{
public:
    int data;
    Num *cap;
    Num() //Constructor
    {
        cap = this;
    }
    Num *root()
    {
        Num *res=this;
        while(res->cap != res)
            res = res->cap;
        return res;
    }
};
Num num[MAX];
void unionNum(Num *x,Num *y)
{
    x = x->root();
    y = y->root();
    if(x < y)
        y->root()->cap = x;
    else
        x->root()->cap = y;
}
void solve(Num *x,int n)
{
    for(int i = 2;i <= sqrt(n);i++)
    {
        if(n % i == 0)
        {
            unionNum(&num[n],&num[i]);
            if(i != n / i)
                unionNum(&num[i],&num[n/i]);
        }
    }
}
int main()
{
    int n,*a,d=0;
    cin >> n;
    a = new int[n];
    for(int i = 0;i < n;i++)
    {
        cin >> a[i];
        num[a[i]].data = a[i];
        solve(&num[a[i]],a[i]);
    }
    int j = 0;
    for(int  i = 0;i < n;i++)
    {
        j = num[a[i]].root()->data;
        if(!check[j])
        {
            check[j] = true;
            d++;
        }
    }
    cout << d << endl;
    return 0;
}
