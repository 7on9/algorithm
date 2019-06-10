#include <iostream>
#include <math.h>
#include <algorithm>
#define lim 100000
using namespace std;
int A[lim+1],maxn = 0;
int colect(int b,int quest[],bool check[])
{
    int i = 1,s = 0;
    while(i*b <= maxn)
    {
        s += A[i*b];
        i++;
    }    
    check[b] = true;
    quest[b] = s;
    return s;
}
int main()
{
    int n,q,*quest;
    static bool *check;
    cin >> n;
    for (int i = 0; i < n; i++)
        {
            int j;
            cin >> j;
            A[j]++;
            maxn = max(j,maxn);
        }
    A[1] = n;
    cin >> q;
    quest = new int[lim+1];
    check = new bool[lim+1];
    for (int i = 0; i < q; i++)
    {
        int k;
        cin >> k;
        if(k == 1)
            cout << n << endl;
        else
            if(!check[k])
                cout << colect(k,quest,check) << endl;
            else
                cout << quest[k] << endl;
    }
    return 0;
}
