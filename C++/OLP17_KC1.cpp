#include <iostream>
#include <vector>
using namespace std;
int T[100],F[100];
int n,k,m,x,y;
void Update(int k, int l, int r, int x, int y, int value)
{
    if(T[k]!=0)
    {
        F[k]+=T[k];
        T[2*k]+=T[k];
        T[2*k+1]+=T[k];
        T[k]=0;
    }
    if(l>y || r<x) return;
    if(x<=l && y>=r)
    {
        F[k]+=value;
        T[2*k]+=value;
        T[2*k+1]+=value;
        T[k]=0;
        return;
    }
    int m=(l+r)/2;
    Update(2*k,l,m,x,y,value);
    Update(2*k+1,m+1,r,x,y,value);
    F[k]=max(F[2*k],F[2*k+1]);
}
int main()
{
    int d = 0;
    cin >> n >> k;
    for(int i = 1;i <= k;i++)
        {
            cin >> x >> y;
            Update(1,1,n,x,y,1);
        }
    for(int i = 0;i <= n;i++)
        if(T[i] % 3 == 0 && T[i] >= 3)
            d++;
    cout << d << endl;
    return 0;
}
