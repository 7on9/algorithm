#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 300005
#define MAXBIT 100010
using namespace std;
long long res[MAX];
int bit[MAXBIT];
int n;
typedef struct strCoder
{
    int pA;
    int pH;
    int id;
}Coder;
bool cmp(Coder a, Coder b)
{
    if(a.pA == b.pA) return (a.pH < b.pH);
    return (a.pA < b.pA);
}
void update(int i)
{
    for(;i <= MAXBIT;i+=(i&-i))
        bit[i]++;
}
long long get(int i)
{
    long long res = 0;
    for(;i > 0;i-=(i&-i))
        res += bit[i];
    return res;
}
void doIt()
{
    Coder *coder;
    cin >> n;
    coder = new Coder[n];
    //get
    for(int i = 0;i < n; i++)
    {
        cin >> coder[i].pA >> coder[i].pH;
        coder[i].id = i;
    }
    //sort pA, if pA == -> sort pH
    sort(coder,coder+n,cmp);
    update(coder[0].pH);
    
    long long numCoderEqual = 1;
    for(int i = 1;i < n;i ++)
    {
        if(coder[i].pA != coder[i-1].pA || coder[i].pH != coder[i-1].pH)   numCoderEqual = 0;
        numCoderEqual++;
        update(coder[i].pH);
        res[coder[i].id] = get(coder[i].pH) - numCoderEqual;
    }
    for(int i = 0;i < n;i++)
        cout << res[i] << endl;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    doIt();
    return 0;
}
