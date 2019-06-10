#include <iostream>
#include <algorithm>
#include <math.h>
#define MAX 10000001
using namespace std;
int d;
int Root[MAX];
//bool check[MAX];
bool check2[MAX];
void swap(int x,int y)
{
    int p = x;
    x = y;
    y = p;
}
void setR()
{
    for(int i = 0;i < MAX; i++)
    {
        Root[i] = -1;
        //check2[i] = false;
    }
}
int findRoot(int n)
{
    return (Root[n] < 0) ? n : (Root[n] = findRoot(Root[n]));
}
void merge(int x, int y)
{
    if ((x = findRoot(x)) == (y = findRoot(y)))
        return ;
    if (Root[y] < Root[x])
        swap(x, y);
    Root[x] += Root[y];
    Root[y] = x;
}
void solve()
{
    for(int i = 2;i <= sqrt(MAX);i++)
    {
        for(int j = i*i;j <= MAX;j+=i)
            if(check2[j]) 
                {
                    merge(i,j);
                    merge(i,j/i);
                }
    }
}
int main()
{
    ios_base :: sync_with_stdio(0);
    int n,a;
    cin >> n;
    setR();
    for(int i = 0;i < n;i++)
    {
        cin >> a;
        if(!check2[a])
        check2[a] = true;
    }
    solve();
    for(int i = 2;i < MAX;i++)
        if((Root[i] < -1)||(check2[i] && Root[i] == -1))
        {
            check2[i] = false;
            d++;
        }
    cout << d << "\n";
    return 0;
}
