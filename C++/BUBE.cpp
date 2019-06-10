#include <iostream>
#include <algorithm>
long long tong;
long n,k;
using namespace std;
struct StructDoll
{
    bool have = false;
    bool in = false;
    long value;
};
typedef StructDoll Doll;
Doll doll[100005];
bool cmp(Doll bb1,Doll bb2)
{
    return (bb1.value < bb2.value);
}
void zip(Doll doll[],long pos)
{
    if(pos < 0) return;
    for(long j = pos-1 ;j >= 0;j--)
    {
        if (doll[pos].have) return;
        if(doll[pos].value-k >= doll[j].value &&  !doll[j].in && !doll[pos].have)
        {
            //cout << doll[pos].value << endl;
            tong -= doll[j].value;
            doll[j].in = true;
            doll[pos].have = true;
            zip(doll, j);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> doll[i].value;
        tong += doll[i].value;
    }
    sort(doll, doll+n, cmp);
    for(long i = n-1;i >= 0; i--)
        if (!doll[i].in) zip(doll, i) ;
    cout << tong << endl;
    return 0;
}
